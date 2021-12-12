#include "MonteCarlo.h"

/*
    These are helper, class-independent functions to calculate average and std.
    They are supposed to accept as input a std::vector of a generic numerical 
    type and return as output a double value representing the statistic.
*/

template<class T>
double compute_mean(const std::vector<T> samples)
{
    double sum = 0.0;

    for (int i = 0; i < samples.size(); i++) {
        sum += (double)samples[i];
    }

    return sum / samples.size();
}

template<class T>
double compute_std(const std::vector<T> samples)
{
    double sum = 0.0;
    double avg = compute_mean(samples);

    for (int i = 0; i < samples.size(); i++) {
        sum += pow((double)samples[i] - avg, 2);
    }

    return sqrt(sum / samples.size());
}

MonteCarlo::MonteCarlo(int size, int n_samples): network_size(size), n_samples(n_samples)
{
    this->sample_thresholds.resize(n_samples);
}

MonteCarlo::~MonteCarlo()
{
    ;
}

int MonteCarlo::get_network_size()
{
    return this->network_size;
}

void MonteCarlo::set_network_size(int new_size)
{
    this->network_size = new_size;
}

double MonteCarlo::compute_threshold(Percolation* percolation)
{
    int open_sites;
    int x, y, z;

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> dist(0, this->network_size - 1);

    while (!percolation->percolates()) {
        x = dist(generator);
        y = dist(generator);
        z = dist(generator);
        
        percolation->open(x, y, z);
        open_sites = percolation->get_open_sites();
    }

    return (double) open_sites / pow(this->network_size, 3);
}

void MonteCarlo::simulate()
{
    double threshold;

    for (int i = 0; i < n_samples; i++) {
        Percolation* network = new Percolation(this->network_size);
        threshold = this->compute_threshold(network);
        this->sample_thresholds[i] = threshold;
    }

    this->threshold_mean = compute_mean<double>(this->sample_thresholds);
    this->threshold_std = compute_std<double>(this->sample_thresholds);
}

double MonteCarlo::get_threshold()
{
    return this->threshold_mean;
}

double MonteCarlo::get_threshold_std()
{
    return this->threshold_std;
}

std::vector<double> MonteCarlo::get_sample_thresholds()
{
    return this->sample_thresholds;
}
