#include <stdexcept>
#include <algorithm>  

#include "Percolation.h"

int Percolation::test_coords(int x, int y, int z)
{
    return this->get_site_from_coordinates(x, y, z);
}

Percolation::Percolation(int n) : n(n), n_sites(n * n * n)
{
    this->sites = new WeightedQuickUnionUF(this->n_sites + 2);
    this->open_sites.resize(this->n_sites + 2);

    this->open_sites.assign(this->n_sites + 1, false);

    /*
        We added an open block in the beginning and another one 
        at the end to simplify the percolates() method.
    */
   this->open_sites[0] = true;
   this->open_sites[this->n_sites + 1] = true;
}

Percolation::~Percolation()
{
    delete this->sites;
}

/*
    Below methods are private because they are "auxillary" to the 
    chosen public API (methods). They are used only by the public
    methods, which can be called externally.
*/

inline int Percolation::get_site_from_coordinates(int x, int y, int z)
{
    return 1 + (z * this->n * this->n) + (y * this->n) + x;
}

inline bool Percolation::validate(int x, int y, int z)
{
    int cell = this->get_site_from_coordinates(x, y, z);
    return cell >= 0 && cell <= this->n_sites + 1;
}

void Percolation::connect_adjacent_cells(int x, int y, int z)
{
    int cell = this->get_site_from_coordinates(x, y, z);

    if (this->validate(x - 1, y, z)) {
        int adj_cell = this->get_site_from_coordinates(x - 1, y, z);
        this->sites->do_union(cell, adj_cell);
    }

    if (this->validate(x + 1, y, z)) {
        int adj_cell = this->get_site_from_coordinates(x + 1, y, z);
        this->sites->do_union(cell, adj_cell);
    }

    if (this->validate(x, y - 1, z)) {
        int adj_cell = this->get_site_from_coordinates(x, y - 1, z);
        this->sites->do_union(cell, adj_cell);
    }

    if (this->validate(x, y + 1, z)) {
        int adj_cell = this->get_site_from_coordinates(x, y + 1, z);
        this->sites->do_union(cell, adj_cell);
    }

    if (this->validate(x, y, z - 1)) {
        int adj_cell = this->get_site_from_coordinates(x, y, z - 1);
        this->sites->do_union(cell, adj_cell);
    }

    if (this->validate(x, y, z + 1)) {
        int adj_cell = this->get_site_from_coordinates(x, y, z + 1);
        this->sites->do_union(cell, adj_cell);
    }

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
    this->connect_adjacent_cells(x, y, z);
}

bool Percolation::percolates()
{
    return this->sites->are_connected(0, this->n_sites + 1);
}

int Percolation::get_open_sites()
{
    return std::count(this->open_sites.begin(), this->open_sites.end(), true);
}

bool Percolation::is_open(int x, int y, int z)
{
    return this->validate(x, y, z) and this->open_sites[this->get_site_from_coordinates(x, y, z)];
}

bool Percolation::is_full(int x, int y, int z)
{
    // To keep things simple, a site is full if it's connected to the site at index 0
    return this->sites->are_connected(0, this->get_site_from_coordinates(x, y, z));
}