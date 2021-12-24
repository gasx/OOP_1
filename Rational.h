//
#ifndef OOP_LAB1_RATIONAL_H
#define OOP_LAB1_RATIONAL_H

#include <iostream>
#include <cmath>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

// Класс «Рациональное число»
class Rational
{
protected:
    static signed long long ulong_abs(long long arg);

    Rational gcdNormalize()
    {
        // Нормализация числа при помощи алгоритма Евклида
        signed long long A = ulong_abs(p), B = ulong_abs(q);
        while ((A != 0) && (B != 0))
        {
            if (A > B)
            {
                A %= B;
            }
            else
            {
                B %= A;
            }
        }
        if ((A + B) != 0)
        {
            p /= (A + B), q /= (A + B);
        }
        else
        {
            p = 0, q = 1;
        }
        return *this;
    }

public:
    long long p, q;

    // Конструктор
    explicit Rational(long long p = 0, long long q = 1) : p(p), q(q)
    {
        if (q != 0)
        {
            gcdNormalize();
            return;
        }
        throw std::invalid_argument("Q == 0!");
    }

    // Сложение рациональных чисел
    Rational operator +(const Rational &arg) const;

    // Вычитание рациональных чисел
    Rational operator -(const Rational &arg) const;

    // Умножение рациональных чисел
    Rational operator *(const Rational &arg) const;

    // Деление рациональных чисел
    Rational operator /(const Rational &arg) const;

    // Проверка на равенство
    bool operator ==(const Rational &arg) const;

    // Проверка на неравенство
    bool operator !=(const Rational &arg) const;

    // Больше
    bool operator >(const Rational &arg) const;

    // Меньше
    bool operator <(const Rational &arg) const;

    // Больше или равно
    bool operator >=(const Rational &arg) const;

    // Меньше или равно
    bool operator <=(const Rational &arg) const;

    // Оператор приведения к типу bool
    explicit operator bool() const
    {
        return p != 0;
    }

    // Преобразование в вещественное число
    double toDouble() const ;


    // Дружественный оператор для вывода рационального числа в выходной поток os (cout, ...)
    friend std::ostream &operator <<(std::ostream &os, const Rational &arg)
    {
        return os << arg.p << '/' << arg.q;
    }
};

#endif //OOP_LAB1_RATIONAL_H
