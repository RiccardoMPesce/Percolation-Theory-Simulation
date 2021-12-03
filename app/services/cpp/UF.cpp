#include <iostream>

#include "UF.hpp"

UnionFind::UnionFind(int n) 
{
    if (n < 0) {
        throw std::invalid_argument("n must be equal or greater than 0");
    }
    this->count_ = n;
    this->parent_ = std::vector<int>(n);
    this->rank_ = std::vector<int>(n);
    
    for (int i = 0; i < n; i++) {
        this->parent_[i] = i;
        this->rank_[i] = 0;
    }
}

void UnionFind::do_union(int p, int q)
{
    int root_p = this->do_find(p);
    int root_q = this->do_find(q);

    if (root_p == root_q) {
        return;
    }

    if (this->rank_[root_p] < this->rank_[root_q]) {
        this->parent_[root_p] = root_q;
    }
    else if (this->rank_[root_p] > this->rank_[root_q]) {
        this->parent_[root_q] = root_p;
    }
    else {
        this->parent_[root_q] = root_p;
        this->rank_[root_p] += 1;
    }

    this->count_ -= 1;
}
