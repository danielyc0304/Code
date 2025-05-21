#include <iostream>
using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {
        int die[6] = {1, 6, 2, 5, 3, 4};  // top,bottom,north,south,west,east

        for (int i = 0; i < n; ++i) {
            string command;

            cin >> command;

            if (command == "north") {
                int bottom = die[1];

                die[1] = die[2];  // north->bottom
                die[2] = die[0];  // top->north
                die[0] = die[3];  // south->top
                die[3] = bottom;  // bottom->south
            } else if (command == "east") {
                int bottom = die[1];

                die[1] = die[5];  // east->bottom
                die[5] = die[0];  // top->east
                die[0] = die[4];  // west->top
                die[4] = bottom;  // bottom->west
            } else if (command == "south") {
                int bottom = die[1];

                die[1] = die[3];  // south->bottom
                die[3] = die[0];  // top->south
                die[0] = die[2];  // north->top
                die[2] = bottom;  // bottom->north
            } else {              // west
                int bottom = die[1];

                die[1] = die[4];  // west->bottom
                die[4] = die[0];  // top->west
                die[0] = die[5];  // east->top
                die[5] = bottom;  // bottom->east
            }
        }

        cout << die[0] << endl;  // top
    }

    return 0;
}
