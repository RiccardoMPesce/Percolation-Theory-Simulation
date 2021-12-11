#include "MonteCarlo.h"

MonteCarlo::MonteCarlo(int size, int n_samples=20): network_size(size), n_samples(n_samples)
{
    this->sample_thresholds.resize(n_samples);
    this->network = new Percolation(size);
}

MonteCarlo::~MonteCarlo()
{
    delete this->network;
}

int MonteCarlo::get_network_size()
{
    return this->network_size;
}