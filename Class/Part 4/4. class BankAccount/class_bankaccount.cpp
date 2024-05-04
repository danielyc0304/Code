#include <iostream>
using namespace std;

class BankAccount {
  private:
    string name;
    int balance;

  public:
    BankAccount(string name, int balance) {
        this->name = name;
        this->balance = balance;
    }

    string getOwner() { return name; }
    int getBalance() { return balance; }

    void deposit(int money) { balance += money; }
    void withdraw(int money) { balance -= money; }
};

int main() {
    string name;
    cin >> name;

    int balance;
    scanf("%d", &balance);

    BankAccount account(name, balance);

    printf("%s\n", account.getOwner().c_str());
    printf("%d\n", account.getBalance());

    account.deposit(40);
    printf("%d\n", account.getBalance());

    account.withdraw(50);
    printf("%d\n", account.getBalance());

    return 0;
}
