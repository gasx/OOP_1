#include "Vector.h"

double Vector::length() const {
    double s = 0;
    for (size_t i = 0; i < n_; ++i)
    {
        s += values_[i] * values_[i];
    }
    return sqrt(s);
}

double Vector::scalar(const Vector &arg) const noexcept(false)
{
    if (n_ == arg.n_)
    {
        double s = 0;
        for (size_t i = 0; i < n_; ++i)
        {
            s += values_[i] * arg.values_[i];
        }
        return s;
    }
    throw std::invalid_argument("Вектор. Скалярный метод. N != ARG.N");
}

// Оператор сложения векторов
Vector Vector::operator +(const Vector &arg) const noexcept(false)
{
    if (n_ == arg.n_)
    {
        Vector result(n_);
        for (size_t i = 0; i < n_; ++i)
        {
            result.values_[i] = values_[i] + arg.values_[i];
        }
        return result;
    }
    throw std::invalid_argument("Вектор. Оператор +. N != ARG.N");
}

// Оператор смены знака вектора
Vector Vector::operator -() const
{
    Vector result(n_);
    for (size_t i = 0; i < n_; ++i)
    {
        result.values_[i] = -values_[i];
    }
    return result;
}

// Оператор вычитания
Vector Vector::operator -(const Vector &arg) const noexcept(false)
{
    if (n_ == arg.n_)
    {
        Vector result(n_);
        for (size_t i = 0; i < n_; ++i)
        {
            result.values_[i] = values_[i] - arg.values_[i];
        }
        return result;
    }
    throw std::invalid_argument("Вектор. Оператор -. N != ARG.N");
}

// Оператор == сравнения векторов
bool Vector::operator ==(const Vector &arg) const
{
    if (n_ == arg.n_)
    {
        for (size_t i = 0; i < n_; ++i)
        {
            if (values_[i] != arg.values_[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

// Оператор != сравнения векторов
bool Vector::operator !=(const Vector &arg) const
{
    return !(operator==(arg));
}
