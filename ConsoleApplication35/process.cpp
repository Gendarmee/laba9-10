#include "processing.h"
#include <iostream>

int process(int month)
{
    // ��� ��� ��� ���������� ������� �������� ����� � ��������� ������

    double averageWindSpeed = 0.0;

    // ������: ����������� � ������������ ������ � �������� ����� � ������ ���� ������ � ��������� ������� ��������
    int daysInMonth = 31; // ������������, ��� ����� ����� 31 ����
    double totalWindSpeed = 0.0;

    for (int day = 1; day <= daysInMonth; ++day)
    {
        double windSpeed;
        std::cout << "������� �������� ����� ��� ��� " << day << ": ";
        std::cin >> windSpeed;

        totalWindSpeed += windSpeed;
    }

    averageWindSpeed = totalWindSpeed / daysInMonth;

    return averageWindSpeed;
}