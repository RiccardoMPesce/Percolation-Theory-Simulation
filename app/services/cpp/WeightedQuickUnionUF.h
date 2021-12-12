#ifndef WEIGHTEDUF_H
#define WEIGHTEDUF_H

#include <vector>

class WeightedQuickUnionUF
{
    private:
        std::vector<int> parent;
        std::vector<int> size;
        int count;
    public:
        WeightedQuickUnionUF(int n);
        ~WeightedQuickUnionUF();

        void do_union(int p, int q);
        int do_find(int p);
        inline bool are_connected(int p, int q);
        inline int get_count();       
};

#endif