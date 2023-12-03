#include <iostream>
#include <Windows.h>


int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

void insertAdditions(int s, int a) {
    int s_copy = s;
    int a_copy = a;


    int s_digits = 0;
    int a_digits = 0;
    while (s_copy > 0) {
        s_copy /= 10;
        ++s_digits;
    }
    while (a_copy > 0) {
        a_copy /= 10;
        ++a_digits;
    }


    int max_additions = a_digits - s_digits;


    for (int additions = 1; additions <= max_additions; ++additions) {
        int current_a = a;
        int divisor = power(10, s_digits + additions - 1);


        for (int i = 0; i < additions; ++i) {
            int digit = current_a / divisor % 10;
            current_a += digit * power(10, i);
        }


        if (current_a == s) {
            std::cout << "Мінімальна кількість операцій додавання: " << additions << std::endl;
            return;
        }
    }

    std::cout << "Неможливо вирішити задачу" << std::endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int s, a;
    std::cout << "Введіть s та a: ";
    std::cin >> s >> a;

    insertAdditions(s, a);

    return 0;
}
