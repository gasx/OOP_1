#ifndef OOP_LAB1_VECTOR_H
#define OOP_LAB1_VECTOR_H

#include <iostream>
#include <cmath>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

class Vector
{
private:
    // Число элементов
    size_t n_;
    // Массив со значениями
    double *values_ = nullptr;

public:
    // Конструктор
    explicit Vector(size_t n = 3) : n_(n)
    {
        if (n_ > 0)
        {
            values_ = new double[n_] {0};
        }
    }

    // Конструктор копирования
    Vector(const Vector &arg) : Vector(arg.n_)
    {
        n_ = arg.n_;
        if (n_ > 0)
        {
            values_ = new double[n_];
            std::copy(arg.values_, arg.values_ + arg.n_, values_);
        }
    }

    friend void swap(Vector &first, Vector &second) noexcept
    {
        std::swap(first.n_, second.n_);
        std::swap(first.values_, second.values_);
    }

    // Оператор копирования
    Vector &operator=(const Vector &arg)
    {
        Vector temp(arg);
        swap(*this, temp);
        return *this;
    }

    // Конструктор перемещения
    Vector(Vector &&arg) noexcept
    {
        n_ = arg.n_, arg.n_ = 0;
        values_ = arg.values_, arg.values_ = nullptr;
    }

    // Оператор перемещения
    Vector &operator=(Vector &&arg) noexcept
    {
        if (this != &arg)
        {
            swap(*this, arg);
            delete[] arg.values_, arg.values_ = nullptr;
            arg.n_ = 0;
        }
        return *this;
    }

    // Деструктор
    virtual ~Vector()
    {
        delete[] values_;
    }

    // Оператор индексации
    double &operator[](size_t k)
    {
        return values_[k];
    }

    // Метод для получения размерности вектора
    size_t size() const
    {
        return n_;
    }

    // Оператор сложения векторов
    Vector operator +(const Vector &arg) const noexcept(false);

    // Оператор сложения векторов и присваивания
    Vector &operator +=(const Vector &arg) noexcept(false)
    {
        if (n_ == arg.n_)
        {
            for (size_t i = 0; i < n_; ++i)
            {
                values_[i] = values_[i] + arg.values_[i];
            }
            return *this;
        }
        throw std::invalid_argument("Вектор. Оператор +=. N != ARG.N");
    }

    // Оператор смены знака вектора
    Vector operator -() const;

    // Оператор вычитания
    Vector operator -(const Vector &arg) const noexcept(false);

    // Оператор вычитания векторов и присваивания
    Vector &operator -=(const Vector &arg) noexcept(false)
    {
        if (n_ == arg.n_)
        {
            for (size_t i = 0; i < n_; ++i)
            {
                values_[i] = values_[i] - arg.values_[i];
            }
            return *this;
        }
        throw std::invalid_argument("Вектор. Оператор -=. N != ARG.N");
    }

    // Метод вычисления длины вектора
    double length() const;

    // Метод вычисления скалярного произведения векторов
    double scalar(const Vector &arg) const noexcept(false);


    // Оператор == сравнения векторов
    bool operator ==(const Vector &arg) const;

    // Оператор != сравнения векторов
    bool operator !=(const Vector &arg) const;

    // Оператор приведения к типу bool
    explicit operator bool() const
    {
        return n_ != 0;
    }

    // Дружественный оператор для вывода вектора в выходной поток os (cout, ...)
    friend std::ostream &operator<<(std::ostream &os, const Vector &arg)
    {
        if (arg.n_ > 0)
        {
            os << '{' << arg.values_[0];
            for (size_t i = 1; i < arg.n_; ++i)
            {
                os << ", " << arg.values_[i];
            }
            return os << '}';
        }
        return os;
    }
};

#endif //OOP_LAB1_VECTOR_H
