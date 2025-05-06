#include "Polynomial.h"

#include <iostream>

using namespace std;

void Polynomial::print() {
    /*
     *  TODO: Print the polynomial.
     */

    bool first = true;

    for (int i = 4; i >= 0; --i) {
        // 第二個條件式：如果前面都沒有元素且已經到常數項了
        if (m_data[i] != 0 || first && i == 0) {
            if (!first && m_data[i] > 0) {
                cout << "+";
            } else if (m_data[i] < 0) {
                cout << "-";
            }

            // 第二個條件式：如果是常數項就一定要輸出
            if (abs(m_data[i]) != 1 || i == 0) {
                cout << abs(m_data[i]);
            }

            switch (i) {
                case 4:
                    cout << "x^4";
                    break;
                case 3:
                    cout << "x^3";
                    break;
                case 2:
                    cout << "x^2";
                    break;
                case 1:
                    cout << "x";
                    break;
                default:
                    break;
            }

            first = false;
        }
    }

    cout << endl;
}

void Polynomial::add(Polynomial poly) {
    /*
     *  TODO: Add two polynomial and print the result.
     */

    for (int i = 0; i < 3; ++i) {
        m_data[i] += poly.m_data[i];
    }

    print();
}

void Polynomial::multiple(Polynomial poly) {
    /*
     *  TODO: Multiply two polynomial and print the result.
     */

    int tmp[5] = {0};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tmp[i + j] += m_data[i] * poly.m_data[j];
        }
    }

    for (int i = 0; i < 5; ++i) {
        m_data[i] = tmp[i];
    }

    print();
}