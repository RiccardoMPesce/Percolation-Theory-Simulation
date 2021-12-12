#include <iostream>

#include "MonteCarlo.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cout << "Missing size and/or number of simulations" << std::endl;
        return - 1;
    }
    
    MonteCarlo* mc = new MonteCarlo(11, 50);
    mc->simulate();
    std::cout << "Threshold:" << " " << mc->get_threshold() << std::endl;
    std::cout << "Threshold std:" << " " << mc->get_threshold_std() << std::endl;
    delete mc;
    return 0;
}