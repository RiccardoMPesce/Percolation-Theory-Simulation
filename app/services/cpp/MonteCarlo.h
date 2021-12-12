#ifndef MONTECARLO_H
#define MONTECARLO_H

#include <iostream>
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

        double threshold_mean;
        double threshold_std;
        
        std::vector<double> sample_thresholds;
        std::vector<int> results_custom_p;

        double compute_threshold(Percolation* percolation);
    public:
        MonteCarlo(int size);
        ~MonteCarlo();

        inline int get_network_size();
        inline void set_network_size(int new_size);
        inline double get_threshold();
        inline double get_threshold_std();
        
        inline std::vector<double> get_sample_thresholds();
        inline std::vector<int> get_results_custom_p();

        void simulate(int sample_size=50);
        void simulate_custom_p(double p_custom, int sample_size=50);
};

#endif