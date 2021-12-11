#include "MonteCarlo.h"

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

double MonteCarlo::compute_mean()
{
    double sum = 0.0;

    for (int i = 0; i < this->n_samples; i++) {
        sum += this->sample_thresholds[i];
    }

    return sum / this->n_samples;
}

double MonteCarlo::compute_std()
{
    double sum = 0.0;

    for (int i = 0; i < this->n_samples; i++) {
        sum += pow(this->sample_thresholds[i] - this->threshold_mean, 2);
    }

    return sqrt(sum / this->n_samples);
}

void MonteCarlo::simulate()
{
    double threshold;

    for (int i = 0; i < n_samples; i++) {
        Percolation* network = new Percolation(this->network_size);
        threshold = this->compute_threshold(network);
        this->sample_thresholds[i] = threshold;
    }

    this->threshold_mean = this->compute_mean();
    this->threshold_std = this->compute_std();
}

double MonteCarlo::get_threshold()
{
    return this->threshold_mean;
}

double MonteCarlo::get_threshold_std()
{
    return this->threshold_std;
}
