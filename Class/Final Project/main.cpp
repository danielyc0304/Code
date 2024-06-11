#include <termios.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;

char getch() {  // 來自助教的程式碼
    char buf = 0;
    struct termios old = {0};

    // 獲取終端屬性
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    // 設定新終端屬性
    old.c_lflag &= ~ICANON;  // 禁用行緩衝（立即讀取）
    old.c_lflag &= ~ECHO;    // 禁用回聲（不顯示在終端）
    old.c_cc[VMIN] = 1;      // 最小字符數
    old.c_cc[VTIME] = 0;     // 無限等待直到輸入
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");

    // 讀取一個字元
    if (read(0, &buf, 1) < 0) perror("read()");

    // 恢復終端屬性
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");

    return buf;
}

bool login(string &username_input, map<string, string> password) {
    // 輸入帳號
    printf("Enter your username: ");
    getline(cin, username_input);

    // 輸入密碼
    string password_input;
    printf("Enter your password: ");
    fflush(stdout);

    while (true) {
        char c = getch();

        switch (c) {
            case 127:  // '\b'
                if (password_input.length() != 0) {
                    printf("\b \b");  // 退格，目前不知道為什麼要寫兩個\b
                    fflush(stdout);
                    password_input.pop_back();
                }

                break;

            case '\n':
                printf("\n");

                break;

            default:
                printf("*");
                fflush(stdout);
                password_input.push_back(c);
        }
        if (c == '\n') {
            break;
        }
    }

    return (password[username_input] == password_input);
}

void displayMenu(string username, int money, int selectedIndex, string menu[]) {
    system("clear");

    printf("Hi %s\n", username.c_str());
    printf("Welcome to the Funland Game Center!\n");
    printf("You have %d coins\n", money);
    printf("Please select a game:\n");
    for (int i = 0; i < 4; ++i) {
        printf("%c %s\n", (i == selectedIndex) ? '>' : ' ', menu[i].c_str());
    }

    return;
}

void showBoard1(char dic[3], int board[3][3]) {
    printf("  0 1 2\n");
    for (int i = 0; i <= 2; i++) {
        printf("%d %c %c %c\n", i, dic[board[i][0]], dic[board[i][1]],
               dic[board[i][2]]);
    }

    return;
}
int win(int board[3][3]) {
    if ((board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1) ||
        (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1) ||
        (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1)) {
        return 1;
    } else if ((board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1) ||
               (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1) ||
               (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1)) {
        return 1;
    } else if ((board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) ||
               (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1)) {
        return 1;
    } else if ((board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 2) ||
               (board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 2) ||
               (board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 2)) {
        return 2;
    } else if ((board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 2) ||
               (board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 2) ||
               (board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 2)) {
        return 2;
    } else if ((board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) ||
               (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2)) {
        return 2;
    } else if (board[0][0] && board[0][1] && board[0][2] && board[1][0] &&
               board[1][1] && board[1][2] && board[2][0] && board[2][1] &&
               board[2][2]) {
        return 3;
    }

    return 0;
}
int ticTacToe(int money) {
    char dic[3] = {'-', 'O', 'X'};
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    showBoard1(dic, board);

    while (true) {
        // 輸入位置
        int row, column;
        printf(
            "Your turn! Please enter the position to place your piece (row "
            "column): ");
        while (scanf("%d %d", &row, &column), cin.get()) {
            if (row < 0 || row > 2 || column < 0 || column > 2 ||
                board[row][column] != 0) {
                printf("Invalid position, please enter again: ");
            } else {
                break;
            }
        }
        board[row][column] = 1;
        if (win(board) == 1) {  // 玩家贏
            printf("You win!\n");
            showBoard1(dic, board);

            printf("You win\n");
            printf("Gain 100 coins\n");

            return money + 100;
        } else if (win(board) == 3) {  // 平手
            printf("Tie!\n");
            showBoard1(dic, board);

            printf("Tie\n");

            return money;
        }
        showBoard1(dic, board);

        // 電腦隨機選擇
        printf("Cmputer is thinking...\n");
        while (true) {
            srand(time(NULL));

            row = rand() % 3;
            column = rand() % 3;

            if (board[row][column] == 0) {
                board[row][column] = 2;

                break;
            }
        }
        if (win(board) == 2) {  // 電腦贏
            printf("You lose!\n");
            showBoard1(dic, board);

            printf("You lose\n");

            return money;
        }
        showBoard1(dic, board);
    }

    return money;
}

void showBoard2(unordered_set<int> num, bool board[5][5]) {
    unordered_set<int>::iterator it = num.begin();
    for (int i = 4; i >= 0; i--) {
        for (int j = 4; j >= 0; j--) {
            if (board[i][j] == false) {
                printf("%-8d", *it);
            } else {
                printf("*       ");
            }
            it++;
        }
        printf("\n");
    }

    return;
}
int bingo(int money) {
    unordered_set<int> random;
    srand(time(NULL));
    while (random.size() < 25) {
        random.insert(rand() % 100 + 1);
    }

    bool board[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = false;
        }
    }

    printf("Here is your Bingo card:\n");
    showBoard2(random, board);
    printf("The computer will now start calling numbers.\n");
    printf("If a number is on your Bingo card, it will be marked.\n");

    int c_row[5] = {0}, c_column[5] = {0};
    for (int i = 1; i <= 25; i++) {
        unordered_set<int> guess;

        int num;
        while (true) {
            num = rand() % 100 + 1;
            if (guess.insert(num).second == true) {
                break;
            }
        }
        printf("%d Number called: %d\n", i, num);

        if (random.find(num) != random.end()) {
            int pos = distance(random.begin(), random.find(num));

            board[pos / 5][pos % 5] = true;
            c_row[4 - pos / 5]++;
            c_column[4 - pos % 5]++;
        }
        showBoard2(random, board);

        for (int j = 0; j < 5; j++) {
            if (c_row[j] == 5 || c_column[j] == 5) {
                printf("BINGO!\n");
                printf("You got bingo\n");
                printf("Gain 100 coins\n");

                return money + 100;
            }
        }
        if ((board[0][0] == true && board[1][1] == true &&
             board[2][2] == true && board[3][3] == true &&
             board[4][4] == true) ||
            (board[0][4] == true && board[1][3] == true &&
             board[2][2] == true && board[3][1] == true &&
             board[4][0] == true)) {
            printf("BINGO!\n");
            printf("You got bingo\n");
            printf("Gain 100 coins\n");

            return money + 100;
        }

        if (i != 25) {
            printf("Press any key to continue...\n");
            getch();  // pause
        }
    }

    printf("You didn't got bingo :(\n");

    printf("Press any key to continue...\n");
    getch();  // pause

    return money - 100;
}

void saveData(map<string, string> password, map<string, int> money) {
    fstream output("accounts.txt", ios::out);
    for (auto it = password.begin(); it != password.end(); it++) {
        output << it->first << " " << it->second << " " << money[it->first]
               << endl;
    }

    return;
}

int main() {
    system("clear");

    // 處理帳戶資料
    fstream input("accounts.txt", ios::in);
    map<string, string> password;
    map<string, int> money;

    string username, tmp1, tmp2;
    while (input >> username >> tmp1 >> tmp2) {
        password[username] = tmp1;
        money[username] = stoi(tmp2);
    }

    string username_input,
        menu[4] = {"Tic Tac Toe", "Bingo", "Change user", "Exit"};
    int selectedIndex = 0;
    while (true) {
        if (login(username_input, password)) {
            while (true) {
                displayMenu(username_input, money[username_input],
                            selectedIndex, menu);

                switch (getch()) {
                    case 'w':
                        selectedIndex = (selectedIndex - 1 + 4) % 4;
                        break;
                    case 's':
                        selectedIndex = (selectedIndex + 1) % 4;
                        break;
                    case '\n':
                        switch (selectedIndex) {
                            case 0:  // Tic Tac Toe
                                system("clear");

                                money[username_input] =
                                    ticTacToe(money[username_input]);
                                saveData(password, money);

                                printf("Press any key to continue...\n");
                                getch();  // pause

                                break;
                            case 1:  // Bingo
                                if (money[username_input] < 100) {
                                    printf("You selected: Bingo\n");
                                    printf(
                                        "You don't have enough coins to play "
                                        "this game\n");

                                    printf("Press any key to continue...\n");
                                    getch();  // pause

                                    system("clear");
                                } else {
                                    system("clear");

                                    money[username_input] =
                                        bingo(money[username_input]);
                                    saveData(password, money);
                                }

                                break;
                            case 2:  // Change user
                                system("clear");

                                printf("Press any key to continue...\n");
                                getch();  // pause

                                while (login(username_input, password) ==
                                       false) {
                                    system("clear");
                                    printf("Invalid username or password.\n");
                                }
                                selectedIndex = 0;

                                break;
                            case 3:  // Exit
                                printf("You selected: Exit\n");

                                printf("Press any key to continue...\n");
                                getch();  // pause

                                system("clear");

                                printf("Thank you for playing\n");

                                return 0;
                        }
                        break;
                }
            }
        } else {
            system("clear");

            printf("Invalid username or password.\n");
        }
    }

    return 0;
}
