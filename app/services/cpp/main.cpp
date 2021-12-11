#include <iostream>

#include "Percolation.h"

int main(void)
{
    Percolation *p = new Percolation(10);
    std::cout << p->test_coords(9, 9, 9) << " " << std::endl;
}