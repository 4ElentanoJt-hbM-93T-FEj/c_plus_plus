#include <iostream>
#include <string>

using namespace std;

int main()
{
    /*Дано N десятков целых чисел. Определить, сколько из них могут
    составлять арифметическую прогрессию. Проверку оформить в виде
    функции*/

    srand(time(0));
    cout
        << "Введите количество десятков целых чисел = ";
    int n, difference;
    bool is_progressive = false;
    cin >> n;
    int *p_n = &n, arr[*p_n][10];

    for (int i = 0; i < *p_n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
            // arr[i][j] = rand() % 10 + 1;
        }
    }

    for (int i = 0; i < *p_n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < *p_n; i++)
    {
        cout << "Является ли данная последовательность №" << i + 1 << " прогрессией ? ";
        for (int j = 0; j < 10 - 1; j++)
        {
            if (arr[i][j] - arr[i][j + 1] != arr[i][0] - arr[i][1])
                is_progressive = false;
            else
                is_progressive = true;
        }

        if (is_progressive)
            cout << "Да" << endl;
        else
            cout << "Нет" << endl;
    }
}