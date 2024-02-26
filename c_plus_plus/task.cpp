#include <iostream>
#include <string>
using namespace std;

class Task
{
public:
    void lab_6_task_2()
    {
        // Lab 6 №2
        /*Для группы из N учащихся известны годовые оценки по
        следующим предметам : математика, физика, химия, информатика. Найти
        среднюю в группе оценку по каждому из предметов. Суммирование
        оценок по предмету оформить в подпрограмме.*/
        int n, sum{0};
        cout << "Введите количество учеников ";
        cin >> n;
        int *p_n = &n;
        string subjects[] = {"математика", "физика", "химия", "информатика"};
        int marks[*p_n][4];
        for (string subj : subjects)
            cout << subj << " ";
        cout << endl;
        for (int i = 0; i < *p_n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                marks[i][j] = (rand() % 4) + 2;
                cout << marks[i][j] << " ";
            }
            cout << endl;
        }

        sums(*p_n, subjects, marks);
    }

    void sums(int p_n, string subjects[], int marks[][4])
    {
        int sum = 0;
        cout << endl;

        for (int j = 0; j < 4; j++)
        {
            for (int i = 0; i < p_n; i++)
            {
                sum += marks[i][j];
            }
            cout << "Среднее значение суммы: " << subjects[j] << " = "
                 << (double)sum / (double)p_n << endl;
            sum = 0;
        }
    }

    void lab_6_task_14()
    {
        // Lab 6 №14
        /*Дан двумерный массив из N строк и M столбцов. Определить для
        каждого столбца массива сумму минимального и максимального
        элементов. Найти произведение этих сумм.
        */
        srand(time(0));
        int n, m, min, max, proizved{1};
        cout << "Введите количество столбцов = ";
        cin >> n;
        cout << "Введите количество строк = ";
        cin >> m;
        int *p_n = &n, *p_m = &m;
        int arr[*p_n][*p_m], sum_arr[*p_m];
        for (int i = 0; i < *p_n; i++)
        {
            for (int j = 0; j < *p_m; j++)
            {
                arr[i][j] = (rand() % 10) + 1;
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        for (int j = 0; j < *p_m; j++)
        {
            min = arr[0][0];
            max = arr[0][0];
            for (int i = 0; i < *p_n; i++)
            {
                if (arr[i][j] > max)
                    max = arr[i][j];
                if (arr[i][j] < min)
                    min = arr[i][j];
            }
            sum_arr[j] = max + min;
            cout
                << "Минимальное число = " << min << " Максимальное число = " << max << ", для столбца номером " << j + 1 << endl
                << "Сумма max и min = " << max + min << endl;
        }

        for (int item : sum_arr)
        {
            proizved *= item;
        }
        cout << "Сумма произведений = " << proizved;
    }
};