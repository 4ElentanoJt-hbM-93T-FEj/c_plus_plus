#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string surname, name, birthday;
    int *marks = new int[5];
    int count_exams;
    double avg_marks;

public:
    // string surname, string name, string birthday, int marks[5]
    // Student()
    // {
    // this->surname = surname;
    // this->name = name;
    // this->birthday = birthday;
    // this->marks = marks;
    // print_marks();
    // }
    // void print_marks()
    // {
    //     for (int i = 0; i < 5; i++)
    //     {
    //         cout << marks[i] << " ->> ";
    //     }
    // }
};
