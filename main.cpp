#include <iostream>
#include <cmath>
#include <stdexcept>

#include "Rational.h"
#include "Vector.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "_____________РАЦИОНАЛЬНЫЕ ЧИСЛА_____________" << endl;
    Rational a(5, 6), b(2, 4);
    // Простейшие операции с рациональными числами
    cout << "A: " << a << " (" << a.toDouble() << ")\n";
    cout << "B: " << b << " (" << b.toDouble() << ")\n";
    cout << "A + B: " << a + b << " (" << ( a + b ).toDouble() << ")\n";
    cout << "A - B: " << a - b << " (" << ( a - b ).toDouble() << ")\n";
    cout << "A * B: " << a * b << " (" << ( a * b ).toDouble() << ")\n";
    cout << "A / B: " << a / b << " (" << ( a / b ).toDouble() << ")\n";
    Rational c(123524, 153524), d(4522, 1232);
    cout << "C: " << c << " (" << c.toDouble() << ")\n";
    cout << "D: " << d << " (" << d.toDouble() << ")\n";
    // Отношения рациональных чисел
    cout << "A == B ? " << ( a == b ? "TRUE" : "FALSE" ) << endl;
    cout << "A != B ? " << ( a != b ? "TRUE" : "FALSE" ) << endl;
    cout << "A > B ? " << ( a > b ? "TRUE" : "FALSE" ) << endl;
    cout << "A >= B ? " << ( a >= b ? "TRUE" : "FALSE" ) << endl;
    cout << "A < B ? " << ( a < b ? "TRUE" : "FALSE" ) << endl;
    cout << "A <= B ? " << ( a <= b ? "TRUE" : "FALSE" ) << endl;
    cout << "_____________КЛАСС ВЕКТОРОВ_____________" << endl;
    const size_t N = 3;
    Vector va(N), vb(N);
    for (size_t i = 0; i < N; ++i)
    {
        va[i] = rand() % 100;
        vb[i] = rand() % 100;
    }
    cout << "Размер вектора А: " << va.size() << endl;
    cout << "Размер вектора B: " << vb.size() << endl;
    cout << "Вектор: " << va << endl;
    cout << "-Вектор А: " << -va << endl;
    cout << "Вектор В: " << vb << endl;
    cout << "-Вектор В: " << -vb << endl;
    cout << "Вектор А+В: " << va + vb << endl;
    Vector vc(va); // Конструктор копирования
    vc += vb;
    cout << "Вектор С (Вектор А +В): " << vc << endl;
    cout << "Вектор С == Вектор А + B ? " << ( vc == va + vb ? "TRUE" : "FALSE" ) << endl;
    cout << "Vector A - Vector B: " << va - vb << endl;
    Vector vd = va; // Оператор копирования
    vd -= vb;
    cout << "Вектор D (Вектор А-В): " << vd << endl;
    cout << "Вектор D == Вектор А-В ? " << ( vd == va - vb ? "TRUE" : "FALSE" ) << endl;
    cout << "Вектор А*В (scalar): " << va.scalar(vb) << endl;
    cout << "Длина вектора А: " << va.length() << endl;
    cout << "Длина вектора В: " << vb.length() << endl;
    cout << "Вектор D: " << vd << endl;
    Vector vf(std::move(vd)); // Конструктор перемещения
    cout << "Вектор D: " << vd << endl;
    cout << "Вектор F: " << vf << endl;
    vc = std::move(vf); // Оператор перемещения
    cout << "Вектор F: " << vf << endl;
    cout << "Вектор C: " << vc << endl;
    return 0;
}
