#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

class Polynomial {
  public:
    /*Ascending order*/
    int m_data[5];

    Polynomial() {
        for (int i = 0; i < 5; ++i) {
            m_data[i] = 0;
        }
    }

    Polynomial(int a, int b, int c) {
        m_data[0] = c;
        m_data[1] = b;
        m_data[2] = a;
        m_data[3] = m_data[4] = 0;
    }

    void print();
    void add(Polynomial);
    void multiple(Polynomial);
};
#endif