//
// Created by Nikita on 02.11.2020.
//
#include <iostream>
#include<cmath>
#ifndef OOP_EXERCISE_04_PENTAGON_HPP
#define OOP_EXERCISE_04_PENTAGON_HPP
const double Pi = 3.141592653589;

template<class T>
struct Pentagon{
    std::pair<T, T> Cord;
    T Base;
    Pentagon(const std::pair<T, T> & cord, T base) : Cord(cord), Base(base){}
};

template<class T>
T CalcSquare(const Pentagon<T> & pentagon){
    T S = pentagon.Base*pentagon.Base*5/4*tan(Pi/5);
    return S;
}

template<class T>
std::ostream & operator << (std::ostream & out, const Pentagon<T> & pentagon) {
    T X1, Y1;
    std::pair<T, T>second_pair(X1, Y1);
    second_pair.first = pentagon.Cord.first - pentagon.Base * cos(72 *Pi/180);
    second_pair.second = pentagon.Cord.second + pentagon.Base * sin(72 * Pi/180);
    out << "pentagon coordinates: [";
    out << pentagon.Cord << ", ";
    out << second_pair << ", ";
    second_pair.first += pentagon.Base * cos(36*Pi/180);
    second_pair.second += pentagon.Base * sin(36*Pi/180);
    out << second_pair << ", ";
    second_pair.first += pentagon.Base * cos(36*Pi/180);
    second_pair.second -= pentagon.Base * sin(36*Pi/180);
    out << second_pair << ", ";
    second_pair.first = pentagon.Cord.second;
    second_pair.second = pentagon.Cord.first + pentagon.Base;
    out << second_pair << ", ";
    return out;
}
#endif //OOP_EXERCISE_04_PENTAGON_HPP
