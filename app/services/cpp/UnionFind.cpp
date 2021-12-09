#include <stdexcept>

#include "UnionFind.h"

UnionFind::UnionFind(int n) 
{
    if (n < 0) {
        throw std::invalid_argument("n must be equal or greater than 0");
    }
    this->count = n;
    this->parent = std::vector<int>(n);
    this->rank = std::vector<int>(n);
    
    for (int i = 0; i < n; i++) {
        this->parent[i] = i;
        this->rank[i] = 0;
    }
}

UnionFind::~UnionFind()
{
    ;
}

int UnionFind::do_find(int p)
{   
    // Check that p is within the bounds of our underlying vector
    if (p < 0 || p >= this->parent.size()) {
        throw std::invalid_argument("p out of bounds");
    }

    // Finding the "root" for node p    
    while (p != this->parent[p]) {
        this->parent[p] = this->parent[this->parent[p]];
        p = this->parent[p];
    }

    return p;
}

int UnionFind::get_count()
{
    return this->count;
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
    if (this->rank[root_p] < this->rank[root_q]) {
        this->parent[root_p] = root_q;
    }
    else if (this->rank[root_p] > this->rank[root_q]) {
        this->parent[root_q] = root_p;
    }
    // Alternatively, if ranks are equal, root_p becomes the root
    else {
        this->parent[root_q] = root_p;
        this->rank[root_p] += 1;
    }

    this->count -= 1;
}
