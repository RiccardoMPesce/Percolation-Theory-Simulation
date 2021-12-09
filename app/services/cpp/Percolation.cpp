#include <stdexcept>

#include "Percolation.h"

Percolation::Percolation(int n) : n(n), n_sites(n * n * n)
{
    this->sites = new WeightedQuickUnionUF(this->n_sites);
    this->open_sites.reserve(this->n_sites);
}

/*
    Below methods are private because they are "auxillary" to the 
    chosen public API (methods). They are used only by the public
    methods, which can be called externally.
*/

inline bool Percolation::validate(int x, int y, int z)
{
    return x < this->n && y < this->n && z < this->n;
}

inline int Percolation::get_site_from_coordinates(int x, int y, int z)
{
    return (z * this->n * this->n) + (y * this->n) + x;
}

/*
    Below methods are public and represents the public API we want
    to expose to external entities.
*/

void Percolation::open(int x, int y, int z)
{
    if (!this->validate(x, y, z)) {
        throw std::invalid_argument("Point coordinate out of grid dimensions!");
    }

    this->open_sites[this->get_site_from_coordinates(x, y, z)] = true;

    // Now we have to connect the new site to eventual adjacent open sites
}