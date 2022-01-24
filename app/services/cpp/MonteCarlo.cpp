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

MonteCarlo::MonteCarlo(int size): network_size(size)
{
    ;
}

MonteCarlo::~MonteCarlo()
{
    ;
}

int MonteCarlo::get_network_size()
{
    return network_size;
}

void MonteCarlo::set_network_size(int size)
{
    network_size = size;
}

double MonteCarlo::compute_threshold(Percolation percolation)
{
    int open_sites;
    int x, y, z;

    // Initializing an uniform random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, network_size - 1);

    while (!percolation.percolates()) {
        x = dist(gen);
        y = dist(gen);
        z = dist(gen);
        
        percolation.open(x, y, z);
        open_sites = percolation.get_open_sites();
    }

    return (double) open_sites / pow(network_size, 3);
}

void MonteCarlo::simulate(int sample_size)
{
    sample_thresholds.resize(sample_size);
    double threshold;

    for (int i = 0; i < sample_size; i++) {
        Percolation network = Percolation(network_size);
        threshold = compute_threshold(network);
        sample_thresholds[i] = threshold;
    }

    threshold_mean = compute_mean<double>(sample_thresholds);
    threshold_std = compute_std<double>(sample_thresholds);
}

void MonteCarlo::simulate_custom_p(double p_custom, int sample_size)
{
    results_custom_p.resize(sample_size);

    for (int i = 0; i < sample_size; i++) {
        Percolation network = Percolation(network_size);
        
        // Iterating through the three dimensions of the lattice
        for (int x = 0; x < network_size - 1; x++) {
            for (int y = 0; y < network_size - 1; y++) {
                for (int z = 0; z < network_size - 1; z++) {
                    // Easy way to implement a random generator
                    bool to_open = ((double)(rand() % 10000) / 10000) < p_custom;
                    if (to_open) {
                        network.open(x, y, z);
                    }
                }
            }
        }

        results_custom_p[i] = network.percolates() ? 1 : 0;
    }
}

double MonteCarlo::get_threshold()
{
    return threshold_mean;
}

double MonteCarlo::get_threshold_std()
{
    return threshold_std;
}

std::vector<double> MonteCarlo::get_sample_thresholds()
{
    return sample_thresholds;
}

std::vector<int> MonteCarlo::get_results_custom_p()
{
    return results_custom_p;
}
