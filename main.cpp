#include "pentagon.hpp"
#include "rhomb.hpp"
#include "trapeze.hpp"

/*
 * Ежов Н П М8О-204Б-19
 * Разработать шаблоны классов согласно варианту задания.
 * Параметром шаблона должен являться скалярный тип данных
 * задающий тип данных для оси координат. Классы должны иметь
 * только публичные поля. В классах не должно быть методов,
 * только поля. Фигуры являются фигурами вращения
 * (равнобедренными), за исключением трапеции и прямоугольника.
 * Для хранения координат фигур необходимо использовать
 * шаблон std::pair.
 * Необходимо реализовать две шаблонные функции:
 * - Функция print печати фигур на экран std::cout (печататься
 *   должны координаты вершин фигур). Функция должна принимать на
 *   вход std::tuple с фигурами, согласно варианту задания(минимум
 *   по одной каждого класса).
 * - Функция square вычисления суммарной площади фигур.
 *   Функция должна принимать на вход std::tuple с фигурами,
 *   согласно варианту задания (минимум по одной каждого класса)
 * Создать программу, которая позволяет:
 * - Создает набор фигур согласно варианту задания (как минимум
 *   по одной фигуре каждого типа с координатами типа int
 *   и координатами типа double).
 * - Сохраняет фигуры в std::tuple
 * - Печатает на экран содержимое std::tuple с помощью
 *   шаблонной функции print.
 * - Вычисляет суммарную площадь фигур в std::tuple и
 *   выводит значение на экран.
 * При реализации шаблонных функций допускается использование
 * вспомогательных шаблонов std::enable_if, std::tuple_size,
 * std::is_same.
 * Трапеция, ромб, пятиугольник.
 */

using IntVertex = std::pair<int, int>;

using DoubleVertex = std::pair<long double, long double>;

template<class T1, class T2>
std::ostream & operator << (std::ostream & out, const std::pair<T1, T2> & p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

template<class T, size_t index = 0>
void PrintTuple(T & tup) {
    if constexpr(index < std::tuple_size<T>::value) {
        std::cout << std::get<index>(tup) << std::endl;
        PrintTuple<T, index + 1>(tup);
    }
}

template<class T, size_t index = 0>
long double TotalSquare(T & tup) {
    if constexpr(index < std::tuple_size<T>::value) {
        return (long double)CalcSquare(std::get<index>(tup)) + TotalSquare<T, index + 1>(tup);
    } else {
        return 0;
    }
}

signed main() {
    Rhomb<int> rhombInt(IntVertex(0, 0), 5, 30);
    Pentagon<int> pentagonInt(DoubleVertex(5, 5), 2);
    Trapeze<int> trapezeInt(IntVertex(1, 1), 6, 4, 4);

    Rhomb<long double> rhombDouble = {DoubleVertex(-0.5, -0.5), 2.0, 30.0};
    Pentagon<long double> pentagonDouble(DoubleVertex(-5.0, -2.5), 5.0);
    Trapeze<long double> trapezeDouble(DoubleVertex(-10.0, -10.0), 5.5, 2.5, 3.0);

    auto tup = std::make_tuple(rhombInt, pentagonInt, trapezeInt, rhombDouble, pentagonDouble, trapezeDouble);
    PrintTuple(tup);
    std::cout << "Total square is " << TotalSquare(tup) << std::endl;
    return 0;
}