#include "points2d.h"

#include <array> 
#include <iostream>
#include <string>

using namespace teaching_project;

int main(int argc, char const *argv[])
{
    Points2D<int> a, b;

    a.ReadPoints2D();

    Points2D<int> c = {a};

    std::cout << "about to add" << std::endl;
    std::cout << c << std::endl;
    std::cout << "done adding" << std::endl;
    return 0;
}
