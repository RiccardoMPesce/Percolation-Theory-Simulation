#include <iostream>
#include <string>

#include "UnionFind.h"

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

UnionFind::~UnionFind()
{
    ;
}

int UnionFind::do_find(int p)
{   
    // Check that p is within the bounds of our underlying vector
    if (p < 0 || p >= this->parent_.size()) {
        throw std::invalid_argument("p out of bounds");
    }

    // Finding the "root" for node p    
    while (p != this->parent_[p]) {
        this->parent_[p] = this->parent_[this->parent_[p]];
        p = this->parent_[p];
    }

    return p;
}

int UnionFind::count()
{
    return this->count_;
}

bool UnionFind::are_connected(int p, int q)
{
    // They are connected if the root is the same element
    return this->do_find(p) == this->do_find(q);
}

void UnionFind::do_union(int p, int q)
{
    int root_p = this->do_find(p);
    int root_q = this->do_find(q);

    // The connection is trivial
    if (root_p == root_q) {
        return;
    }

    // The root with the larger rank becomes the root of other one
    // Basically, the lower rank root attaches the larger rank root
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
