//
// Created by Nikita on 02.11.2020.
//
#include <iostream>
#include <tuple>
#include <vector>

#ifndef OOP_EXERCISE_04_TRAPEZE_HPP
#define OOP_EXERCISE_04_TRAPEZE_HPP

template<class T>
struct Trapeze {
    /* Cords of left bottom corner, greater and smaller base, heigth */
    std::pair<T, T> Cord;
    T GreaterBase, SmallerBase, Height;

    Trapeze(const std::pair<T, T> & cord, T greaterBase, T smallerBase, T height) : Cord(cord), GreaterBase(greaterBase), SmallerBase(smallerBase), Height(height) {
        if (SmallerBase > GreaterBase) {
            std::swap(SmallerBase, GreaterBase);
        }
    }
};

template<class T>
T CalcSquare(const Trapeze<T> & trapeze) {
    return (trapeze.Height * (trapeze.GreaterBase + trapeze.SmallerBase)) / 2.0;
}

template<class T>
std::ostream & operator << (std::ostream & out, const Trapeze<T> & trapeze) {
    T d = (trapeze.GreaterBase - trapeze.SmallerBase) / 2.0;
    out << "Trapeze {";
    out << trapeze.Cord << ", ";
    std::pair <T, T>second_pair(trapeze.Cord.first + d, trapeze.Cord.second + trapeze.Height);
    out << second_pair << ", ";
    second_pair = std::pair<T, T>(trapeze.Cord.first + trapeze.SmallerBase + d, trapeze.Cord.second + trapeze.Height);
    out << second_pair << ", ";
    second_pair = std::pair<T, T>(trapeze.Cord.first + trapeze.GreaterBase, trapeze.Cord.second);
    out << second_pair;
    out << "}";
    return out;
}

#endif //OOP_EXERCISE_04_TRAPEZE_HPP
