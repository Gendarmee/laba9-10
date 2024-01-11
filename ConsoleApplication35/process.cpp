#include "processing.h"
#include <iostream>

int process(int month)
{
    // ¬аш код дл€ вычислени€ средней скорости ветра в указанном мес€це

    double averageWindSpeed = 0.0;

    // ѕример: запрашиваем у пользовател€ данные о скорости ветра в каждый день мес€ца и вычисл€ем среднюю скорость
    int daysInMonth = 31; // ѕредполагаем, что мес€ц имеет 31 день
    double totalWindSpeed = 0.0;

    for (int day = 1; day <= daysInMonth; ++day)
    {
        double windSpeed;
        std::cout << "¬ведите скорость ветра дл€ дн€ " << day << ": ";
        std::cin >> windSpeed;

        totalWindSpeed += windSpeed;
    }

    averageWindSpeed = totalWindSpeed / daysInMonth;

    return averageWindSpeed;
}