#ifndef MONTECARLO_H
#define MONTECARLO_H

#include <random>
#include <vector>

#include <math.h>

#include "Percolation.h"

class MonteCarlo 
{
    private:
        int network_size;
        int n_samples;  
        double p_threshold_mean;
        double p_threshold_std;
        std::vector<double> sample_thresholds;
        Percolation* network;
    public:
        MonteCarlo(int size, int n_samples=20);
        ~MonteCarlo();

        int get_network_size();
        int get_n_percolated_samples();
        double get_percolation_threshold_mean();
        double get_percolation_threshold_std();
};

#endif