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
        double threshold_mean;
        double threshold_std;
        std::vector<double> sample_thresholds;

        double compute_threshold(Percolation* percolation);
        double compute_mean();
        double compute_std();
    public:
        MonteCarlo(int size, int n_samples=20);
        ~MonteCarlo();

        int get_network_size();
        double get_threshold();
        double get_threshold_std();

        void simulate();
        
};

#endif