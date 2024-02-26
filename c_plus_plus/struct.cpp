#include <iostream>
#include <string>
#include "student.cpp"
// #include "task.cpp"
using namespace std;

int main()
{
    /*Составить список учебной группы, включающий N (N=3) человек.
    Для каждого студента указать: фамилию и имя, дату рождения (год,
    месяц и число) оценки за сессию (от 3 до 5 экзаменов). Информацию о
    каждом студенте оформить в виде структуры, а совокупность структур
    объединить в массив. Составить программу, которая обеспечивает ввод
    полученной информации, ее просмотр в виде таблицы (рис. 1), а также
    вывод информации на экран монитора согласно конкретному варианту. В
    случае если в группе нет студентов с требуемыми данными, выдать
    соответствующее сообщение*/

    int n, count_exams;
    string surname, name, birthday;
    cout << "Введите количество студентов учебной группы = ";
    cin >> n;
    int *p_n = &n;
    Student list_students[*p_n];
    for (int i = 0; i < *p_n; i++)
    {
        cout << "Информация о студенте №" << i + 1 << endl
             << "Введите фамилию ";
        cin >> surname;
        list_students[i].surname = surname;

        cout << "Введите имя ";
        cin >> name;
        list_students[i].name = name;

        cout << "Введите день рождения ";
        cin >> birthday;
        list_students[i].birthday = birthday;

        do
        {
            cout << "Введите количество оценок, от 3 до 5 = ";
            cin >> count_exams;
        } while (!(count_exams <= 5 && count_exams >= 3));

        list_students[i].count_exams = count_exams;

        cout << "Введите сами оценки ";

        for (int j = 0; j < count_exams; j++)
            cin >> list_students[i].marks[j];

        cout << endl;
    }

    // Вывод информации о студенте
    for (Student item : list_students)
    {
        cout << endl
             << item.surname << " " << item.name << " " << item.birthday << endl;
        cout << "Оценки ";
        for (int j = 0; j < item.count_exams; j++)
            cout << item.marks[j] << " ";
    }

    /*№2 Вывести анкетные данные всех студентов, у которых по всем
    предметам «удовлетворительно»*/

    cout << endl
         << "Вывод информации о студентах у которых по всем предметам «удовлетворительно» " << endl;

    int three_count{0};
    for (Student item : list_students)
    {
        for (int j = 0; j < item.count_exams; j++)
            if (item.marks[j] == 3)
                three_count++;

        if (three_count == item.count_exams)
            cout << item.surname << " " << item.name << " " << item.birthday << endl;

        three_count = 0;
    }
    cout << endl;

    /*№14 Вычислить средний балл группы и вывести список студентов,
    имеющих средний балл ниже, чем в целом по группе.*/

    int list_avg[*p_n];
    double avg{0.0}, sum_avg{0.0}, avg_group{0.0};
    for (int i = 0; i < *p_n; i++)
    {
        for (int j = 0; j < list_students[i].count_exams; j++)
            avg += list_students[i].marks[j];

        list_students[i].avg_marks = avg / (double)list_students[i].count_exams;
        sum_avg += list_students[i].avg_marks;
        avg = 0;
    }
    avg_group = sum_avg / (double)*p_n;

    cout
        << "Срений балл группы = " << avg_group << endl
        << "список студентов, имеющих средний балл ниже, чем в целом по группе " << avg_group << endl;

    for (int i = 0; i < *p_n; i++)
    {
        if (list_students[i].avg_marks < avg_group)
        {
            cout << list_students[i].surname << " " << list_students[i].name << " "
                 << list_students[i].birthday << " " << list_students[i].avg_marks << endl;
        }
    }
}
