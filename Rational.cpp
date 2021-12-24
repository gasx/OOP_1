#include "Rational.h"

signed long long Rational::ulong_abs(long long arg)
{
    // Модуль arg
    if (arg < 0)
    {
        return -arg;
    }
    return arg;
}

double Rational::toDouble () const
{
    return double(p) / double(q);
}

// Сложение рациональных чисел
Rational Rational::operator +(const Rational &arg) const
{
    return Rational(p * arg.q + arg.p * q, q * arg.q).gcdNormalize();
}

// Вычитание рациональных чисел
Rational Rational::operator -(const Rational &arg) const
{
    return Rational(p * arg.q - arg.p * q, q * arg.q).gcdNormalize();
}

// Умножение рациональных чисел
Rational Rational::operator *(const Rational &arg) const
{
    // Умножаем только числитель
    Rational temp(p * arg.p, q);
    // Затем нормализуем число, чтобы уменьшить вероятность переполнения при следующей операции
    temp.gcdNormalize();
    return Rational(temp.p, temp.q * arg.q).gcdNormalize();
}

// Деление рациональных чисел
Rational Rational::operator /(const Rational &arg) const
{
    // Делим только числитель и затем
    Rational temp(p * arg.q, q);
    // Затем нормализуем число, чтобы уменьшить вероятность переполнения при следующей операции
    temp.gcdNormalize();
    return Rational(temp.p, temp.q * arg.p).gcdNormalize();
}

// Проверка на равенство
bool Rational::operator ==(const Rational &arg) const
{
    return (toDouble() == arg.toDouble());
}

// Проверка на неравенство
bool Rational::operator !=(const Rational &arg) const
{
    return (toDouble() != arg.toDouble());
}

// Больше
bool Rational::operator >(const Rational &arg) const
{
    return (toDouble() > arg.toDouble());
}

// Меньше
bool Rational::operator <(const Rational &arg) const
{
    return (toDouble() < arg.toDouble());
}

// Больше или равно
bool Rational::operator >=(const Rational &arg) const
{
    return (toDouble() >= arg.toDouble());
}

// Меньше или равно
bool Rational::operator <=(const Rational &arg) const
{
    return (toDouble() <= arg.toDouble());
}
