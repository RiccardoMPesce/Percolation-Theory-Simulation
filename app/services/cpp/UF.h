#ifndef UF_H
#define UF_H

#include <vector>

class UnionFind
{
    private:
        std::vector<int> parent_;
        std::vector<int> rank_;
        int count_;
    public:
        UnionFind(int n);
        ~UnionFind();

        void do_union(int p, int q);
        int do_find(int p);
        bool are_connected(int p, int q);
        int count();
};

#endif