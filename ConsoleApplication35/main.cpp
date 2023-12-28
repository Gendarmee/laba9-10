#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include "file_reader.h"
#include "book_subscription.h"
using namespace std;

int main() {
    FileReader reader;
    vector<WindInfo> windData = reader.readData("data.txt");
    setlocale(LC_ALL, "Russian");
    string filename = "data.txt";
    vector<WindInfo> data;

    FileReader fileReader;
    data = fileReader.readData(filename);

    int choice;
    cout << "Выберите метод сортировки:\n";
    cout << "1. Сортировка шейкерная по скорости ветра\n";
    cout << "2. Сортировка слиянием по направлению ветра\n";
    cout << "3. Вывести все дни, в которые дул ветер в одном из направлений West, NorthWest или North\n";
    cout << "4. Вывести все дни, в которые дул ветер больше 5 м/с\n";
    cin >> choice;

    switch (choice) {
    case 1:
        shakerSortBySpeed(data);
        for (const auto& wind : data) {
            cout << "Дата: " << wind.day << "." << wind.month << ", Направление: " << wind.direction << ", Скорость: " << wind.speed << "\n";
        }
        break;
    case 2:
        mergeSortByDirection(data, 0, data.size() - 1);
        for (const auto& wind : data) {
            cout << "Дата: " << wind.day << "." << wind.month << ", Направление: " << wind.direction << ", Скорость: " << wind.speed << "\n";
        }
        break;
    case 3: {
        cout << "Дни, в которые дул ветер в одном из направлений West, NorthWest или North:\n";
        bool found = false;
        for (const WindInfo& wind : windData) {
            if (wind.direction == "West" || wind.direction == "NorthWest" || wind.direction == "North") {
                cout << wind.day << "/" << wind.month << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "Нет данных о днях с указанными направлениями ветра.\n";
        }
        break;
    }
    case 4: {
        cout << "Дни, в которые дул ветер со скоростью больше 5 м/с:\n";
        bool found = false;
        for (const WindInfo& wind : windData) {
            if (wind.speed > 5) {
                cout << wind.day << "/" << wind.month << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "Нет данных о днях с ветром скоростью больше 5 м/с.\n";
        }
        break;
    }
    default:
        cout << "Неверный выбор метода сортировки.\n";
        return 0;
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
