#include <iostream>
#include <random>

#include "MonteCarlo.h"

int main(int argc, char **argv)
{
    if (argc < 3) {
        std::cout << "Missing size and/or number of simulations" << std::endl;
        return - 1;
    }

    std::cout << "Size: " << argv[1] << ". Number of simulations: " << argv[2] << "." << std::endl;

    int size = (atoi(argv[1]));
    int n_sims = (atoi(argv[2]));
    
    MonteCarlo* mc = new MonteCarlo(size);
    mc->simulate(n_sims);
    std::cout << "Threshold:" << " " << mc->get_threshold() << std::endl;
    std::cout << "Threshold std:" << " " << mc->get_threshold_std() << std::endl;
    delete mc;
    
    return 0;
}