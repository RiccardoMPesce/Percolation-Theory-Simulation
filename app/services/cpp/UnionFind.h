#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <vector>
#include "UF.h"

class UnionFind: public virtual UF
{
    private:
        std::vector<int> parent;
        std::vector<int> rank;
        int count;
    public:
        UnionFind(int n);
        ~UnionFind();

        void do_union(int p, int q);
        int do_find(int p);
        bool are_connected(int p, int q);
        int get_count();
};

#endif