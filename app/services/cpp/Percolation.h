#include "WeightedUF.h"

class Percolation
{
    private:
        int n;
        WeightedUF* sites;
        
        int get_site_from_coordinates(int x, int y, int z)
        {
            return 5;
        }
    
    public:
        Percolation(int n);

        void open(int row, int col);
        bool is_open(int row, int col);
        bool is_full(int row, int col);
        int get_open_sites();
        bool percolates();
};