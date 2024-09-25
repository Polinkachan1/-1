#include <iostream>
using namespace std;

// ИДЗ
void replacing_bit_divisibility_by_2(int number) {
    cout << "ИДЗ(замена битов исходя из их четности):";
    cout << endl;
    unsigned int mask = 1 << (sizeof(int) * 8) - 1;
    if (number >= 0) {
        for (int i = 0; i <= sizeof(int) * 8 - 1; ++i) {
            putchar((i % 2 != 0) ? '1' : ((number & mask) ? '1' : '0'));
            mask >>= 1;
        };
    }
    else {
        for (int i = 0; i <= sizeof(int) * 8 - 1; ++i) {
            putchar((i % 2 == 0) ? '0' : ((number & mask) ? '1' : '0'));
            mask >>= 1;
        };
    };
}


int main()
{
    setlocale(0, "");
    //1) Сколько памяти (в байтах)отводится под различные типы данных со спецификаторами и без:
    // int, short int, long int, float, double, long double, char и bool.
    cout << "Тип данных int - " << sizeof(int) << "байта" << endl;
    cout << "Тип данных short int - " << sizeof(short int) << "байта" << endl;
    cout << "Тип данных long int - " << sizeof(long int) << "байта" << endl;
    cout << "Тип данных float - " << sizeof(float) << "байта" << endl;
    cout << "Тип данных double - " << sizeof(double) << "байта" << endl;
    cout << "Тип данных long double - " << sizeof(long double) << "байта" << endl;
    cout << "Тип данных char - " << sizeof(char) << "байта" << endl;
    cout << "Тип данных bool - " << sizeof(bool) << "байта" << endl;

    //2) Вывести на экран двоичное представление в памяти (все разряды) целого числа.
    cout << "Введите число типа int: ";
    int int_num;
    cin >> int_num;
    cout << "двоичное представление в памяти(все разряды) целого числа: " << endl;
    unsigned int mask = 1 << (sizeof(int) * 8) - 1;
    for (int i = 0; i <= sizeof(int) * 8 - 1; ++i) {
        putchar(int_num & mask ? '1' : '0');
        mask >>= 1; 
        if (i == 0 || i % 8 == 7) {
            putchar(' ');
        }
    };
    cout << endl;
    replacing_bit_divisibility_by_2(int_num);//ИДЗ
    cout << endl;


    //3) Вывести на экран двоичное представление в памяти (все разряды) типа float.
    union {
        float float_num;
        int float_to_int;
    };

    cout << "Введите число типа float: ";
    cin >> float_num;
    cout << "двоичное представление в памяти (все разряды) типа float" << endl;
    unsigned int mask_float = 1 << (sizeof(int) * 8) - 1;
    for (int i = 0; i <= (sizeof(int) * 8) - 1; ++i) {
        putchar(float_to_int & mask_float ? '1' : '0');
        mask_float >>= 1;
        if (i == 0 || i == 8) {
            putchar(' ');
        }
    }
    cout << endl;

    //4) Вывести на экран двоичное представление в памяти (все разряды) типа double.
    cout << "Введите число типа double: ";
    union {
        double double_num;
        unsigned int double_divided_on_two_parts[2];
    };
    cin >> double_num;
    cout << "двоичное представление в памяти (все разряды) типа double: ";
    cout << endl;
    unsigned int mask_double = 1 << ((sizeof(int) * 8) - 1);
    for (int part = 1; part >= 0; --part) {
        for (int j = 0; j <= (sizeof(int) * 8 - 1); ++j) {
            putchar(double_divided_on_two_parts[part] & mask_double ? '1' : '0');
            mask_double >>= 1;
            if (part == 1 & (j == 0 || j == 11)) {
                putchar(' ');
            };
        };
        mask_double = 1 << ((sizeof(int) * 8) - 1);

    };
    return 0;
}