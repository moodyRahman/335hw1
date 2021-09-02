#include "points2d.h"

#include <array> 
#include <iostream>
#include <string>

using namespace teaching_project;

int main(int argc, char const *argv[])
{
    Points2D<int> a, b;

    a.ReadPoints2D();

    std::cout << a << std::endl;

    return 0;
}
