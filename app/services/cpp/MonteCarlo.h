#ifndef MONTECARLO_H
#define MONTECARLO_H

#include <random>
#include <vector>

#include <math.h>

#include "Percolation.h"

template<class T>
double compute_mean(const std::vector<T> samples);

template<class T>
double compute_std(const std::vector<T> samples);

class MonteCarlo 
{
    private:
        int network_size;
        int n_samples;  
        double threshold_mean;
        double threshold_std;
        std::vector<double> sample_thresholds;
        std::vector<double> sample_thresholds_custom_p;

        double compute_threshold(Percolation* percolation);
    public:
        MonteCarlo(int size, int n_samples=50);
        ~MonteCarlo();

        int get_network_size();
        void set_network_size(int new_size);
        double get_threshold();
        double get_threshold_std();
        std::vector<double> get_sample_thresholds();
        std::vector<double> get_sample_thresholds_custom_p();

        void simulate();
        void simulate_custom_p(double p_custom);
};

#endif