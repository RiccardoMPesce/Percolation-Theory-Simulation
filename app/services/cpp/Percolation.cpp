#include <stdexcept>
#include <algorithm>  

#include "Percolation.h"

int Percolation::test_coords(int x, int y, int z)
{
    return get_site_from_coordinates(x, y, z);
}

Percolation::Percolation(int n) : n(n), n_sites(n * n * n), sites(n_sites + 2)
{
    open_sites.resize(n_sites + 2);
    open_sites.assign(n_sites + 1, false);

    /*
        We added an open block in the beginning and another one 
        at the end to simplify the percolates() method.
    */
   open_sites[0] = true;
   open_sites[n_sites + 1] = true;
}

Percolation::~Percolation()
{
    ;
}

/*
    Below methods are private because they are "auxillary" to the 
    chosen public API (methods). They are used only by the public
    methods, which can be called externally.
*/

int Percolation::get_site_from_coordinates(int x, int y, int z)
{
    return 1 + (z * n * n) + (y * n) + x;
}

bool Percolation::validate(int x, int y, int z)
{
    int cell = get_site_from_coordinates(x, y, z);
    return cell >= 0 && cell <= n_sites + 1;
}

void Percolation::connect_adjacent_cells(int x, int y, int z)
{
    int cell = get_site_from_coordinates(x, y, z);

    if (validate(x - 1, y, z)) {
        int adj_cell = get_site_from_coordinates(x - 1, y, z);
        sites.do_union(cell, adj_cell);
    }

    if (validate(x + 1, y, z)) {
        int adj_cell = get_site_from_coordinates(x + 1, y, z);
        sites.do_union(cell, adj_cell);
    }

    if (validate(x, y - 1, z)) {
        int adj_cell = get_site_from_coordinates(x, y - 1, z);
        sites.do_union(cell, adj_cell);
    }

    if (validate(x, y + 1, z)) {
        int adj_cell = get_site_from_coordinates(x, y + 1, z);
        sites.do_union(cell, adj_cell);
    }

    if (validate(x, y, z - 1)) {
        int adj_cell = get_site_from_coordinates(x, y, z - 1);
        sites.do_union(cell, adj_cell);
    }

    if (validate(x, y, z + 1)) {
        int adj_cell = get_site_from_coordinates(x, y, z + 1);
        sites.do_union(cell, adj_cell);
    }

}

/*
    Below methods are public and represents the public API we want
    to expose to external entities.
*/

void Percolation::open(int x, int y, int z)
{
    if (!validate(x, y, z)) {
        throw std::invalid_argument("Point coordinate out of grid dimensions!");
    }

    open_sites[get_site_from_coordinates(x, y, z)] = true;

    // Now we have to connect the new site to eventual adjacent open sites
    connect_adjacent_cells(x, y, z);
}

bool Percolation::percolates()
{
    return sites.are_connected(0, n_sites + 1);
}

int Percolation::get_open_sites()
{
    return std::count(open_sites.begin(), open_sites.end(), true);
}

bool Percolation::is_open(int x, int y, int z)
{
    return validate(x, y, z) and open_sites[get_site_from_coordinates(x, y, z)];
}

bool Percolation::is_full(int x, int y, int z)
{
    // To keep things simple, a site is full if it's connected to the site at index 0
    return sites.are_connected(0, get_site_from_coordinates(x, y, z));
}