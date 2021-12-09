#include <vector>

#include "WeightedQuickUnionUF.h"

class Percolation
{
    private:
        int n;
        int n_sites;
        WeightedQuickUnionUF* sites;
        std::vector<bool> open_sites;
        
        inline int get_site_from_coordinates(int x, int y, int z);
        inline bool validate(int x, int y, int z);
        
    public:
        Percolation(int n);

        void open(int x, int y, int z);
        bool is_open(int x, int y, int z);
        bool is_full(int x, int y, int z);
        int get_open_sites();
        bool percolates();
};