#include <iostream>

#include "Polynomial.h"

using namespace std;

int main() {
    int num_case;
    cin >> num_case;

    while (num_case--) {
        char command;
        cin >> command;

        Polynomial p1, p2;
        switch (command) {
            case 'p':
                /*TODO: Add something here*/
                cin >> p1.m_data[2] >> p1.m_data[1] >> p1.m_data[0];

                p1.print();

                break;

            /*Deal with other cases*/
            case '+':
                cin >> p1.m_data[2] >> p1.m_data[1] >> p1.m_data[0];
                cin >> p2.m_data[2] >> p2.m_data[1] >> p2.m_data[0];

                p1.add(p2);

                break;
            case '*':
                cin >> p1.m_data[2] >> p1.m_data[1] >> p1.m_data[0];
                cin >> p2.m_data[2] >> p2.m_data[1] >> p2.m_data[0];

                p1.multiple(p2);

                break;
            default:
                cout << "wrong input!" << endl;
                break;
        }
    }
}