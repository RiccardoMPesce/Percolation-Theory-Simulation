#ifndef WEIGHTEDUF_H
#define WEIGHTEDUF_H

#include <vector>
#include "UF.h"

class WeightedUF: public virtual UF 
{
    private:
        std::vector<int> parent;
        std::vector<int> size;
        int count;
    public:
        WeightedUF(int n);
        ~WeightedUF();

        void do_union(int p, int q);
        int do_find(int p);
        bool are_connected(int p, int q);
        int get_count();       
};

#endif