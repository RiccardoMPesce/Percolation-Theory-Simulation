#include <iostream>

#include "MonteCarlo.h"

int main(void)
{
    MonteCarlo* mc = new MonteCarlo(11, 50);
    mc->simulate();
    std::cout << "Threshold:" << " " << mc->get_threshold() << std::endl;
    std::cout << "Threshold std:" << " " << mc->get_threshold_std() << std::endl;
    delete mc;
}