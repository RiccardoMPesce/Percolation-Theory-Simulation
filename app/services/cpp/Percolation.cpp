#include <vector>

#include "WeightedUF.h"
#include "Percolation.h"

Percolation::Percolation(int n)
{
    this->n = n;
    this->sites = new WeightedUF(n);
}