#include <vector>

class Percolation
{
    private:
        std::vector<int> sites;
        
        int get_site_from_coordinates(int x, int y, int z)
        {
            
        }
    
    public:
        Percolation(int n);

        void open(int row, int col);
        bool is_open(int row, int col);
        bool is_full(int row, int col);
        int get_open_sites();
        bool percolates();
};