//
// Created by Nikita on 02.11.2020.
//

#ifndef OOP_EXERCISE_04_RHOMB_HPP
#define OOP_EXERCISE_04_RHOMB_HPP

#include <iostream>
#include <tuple>
#include <vector>
const double PI = 3.141592653589;

template<class T>
struct Rhomb {
    std::pair<T, T> Cord;
    T Base, Phi;

    Rhomb(const std::pair<T, T> & cord, T base, T phi) : Cord(cord), Base(base), Phi(phi) {}
};

template<class T>
T CalcSquare(const Rhomb<T> & rhomb){
    T S = rhomb.Base*rhomb.Base*sin(rhomb.Phi*PI/180);
    return S;
}

template<class T>
std::ostream & operator << (std::ostream & out, const Rhomb<T> & rhomb) {
    T X1, Y1;
    X1 = rhomb.Cord.first + rhomb.Base * cos(rhomb.Phi *PI/180);
    Y1 = rhomb.Cord.second + rhomb.Base * sin(rhomb.Phi * PI/180);
    std::pair <T, T> second_pair(X1, Y1);
    out << "Rhomb coordinates: [";
    out << rhomb.Cord << ", ";
    out << second_pair << ", ";
    second_pair.first += rhomb.Base;
    out << second_pair << ", ";
    second_pair.first = rhomb.Cord.first + rhomb.Base;
    second_pair.second = rhomb.Cord.second;
    out << "]";
    out << second_pair << ", ";
    return out;
}
#endif //OOP_EXERCISE_04_RHOMB_HPP
