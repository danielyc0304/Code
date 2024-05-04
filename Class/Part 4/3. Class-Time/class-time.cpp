#include <iostream>
using namespace std;

class Time {
  private:
    int h, m, s;

  public:
    void setTime(int h, int m, int s) {
        this->h = h;
        this->m = m;
        this->s = s;
    }

    void printTime() { cout << h << ":" << m << ":" << s << endl; }

    int getHour() { return h; }
    int getMinute() { return m; }
    int getSecond() { return s; }

    int timeToSeconds() { return h * 3600 + m * 60 + s; }
};

int main() {
    int h, m, s;
    while (scanf("%d %d %d", &h, &m, &s) != EOF) {
        Time time;
        time.setTime(h, m, s);

        time.printTime();
        printf("%d:%d:%d\n", time.getHour(), time.getMinute(),
               time.getSecond());
        printf("Seconds: %d\n", time.timeToSeconds());
    }

    return 0;
}
