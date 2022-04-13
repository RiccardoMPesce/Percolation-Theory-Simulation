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
    mc->simulate_custom_p(0.2, n_sims);
    for (int i = 0; i < mc->get_results_custom_p().size(); i++) {
        std::cout << mc->get_results_custom_p().at(i) << std::endl;
    }

    delete mc;
    
    return 0;
}