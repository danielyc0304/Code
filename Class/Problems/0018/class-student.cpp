#include <iostream>
using namespace std;

class Student {
  private:
    int id;
    double score1, score2;

  public:
    Student(int id, double score1, double score2) {
        this->id = id;
        this->score1 = score1, this->score2 = score2;
    }

    int get_id() { return id; }
    double total() { return score1 + score2; }
    double mean() { return (score1 + score2) / 2; }
    bool is_pass() { return ((score1 + score2) / 2 >= 60); }
};

int main() {
    int id;
    scanf("%d", &id);

    double score1, score2;
    scanf("%lf %lf", &score1, &score2);

    Student student(id, score1, score2);
    printf("%d\n", student.get_id());
    printf("%g\n", student.total());
    printf("%g\n", student.mean());
    printf("%d\n", student.is_pass());

    return 0;
}
