#include "points2d.h"

#include <array> 
#include <iostream>
#include <string>

using namespace teaching_project;

int main(int argc, char const *argv[])
{
    Points2D<int> a, b;

    a.ReadPoints2D();

    // std::cout << a.sequence_[0][0] << std::endl;
    // std::cout << a.sequence_[0][1] << std::endl;
    // std::cout << a.sequence_[1][0] << std::endl;
    // std::cout << a.sequence_[1][1] << std::endl;
    std::cout << "about to print" << std::endl;
    std::cout << a << std::endl;
    std::cout << "im done printing" << std::endl;
    return 0;
}
