#include <stdexcept>
#include <iostream>

#include "WeightedQuickUnionUF.h"

WeightedQuickUnionUF::WeightedQuickUnionUF(int n)
{
    if (n < 0) {
        throw std::invalid_argument("n must be equal or greater than 0");
    }
    count = n;
    parent.resize(n);
    size.resize(n);
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 0;
    }
}

WeightedQuickUnionUF::~WeightedQuickUnionUF()
{
    ;
}

int WeightedQuickUnionUF::get_count()
{
    return count;
}

int WeightedQuickUnionUF::do_find(int p)
{
    // Check that p is within the bounds of our underlying vector
    if (p < 0 || p >= parent.size()) {
        throw std::invalid_argument("p out of bounds");
    }

    // Finding the "root" for node p    
    while (p != parent[p]) {
        parent[p] = parent[parent[p]];
        p = parent[p];
    }

    return p;
}

bool WeightedQuickUnionUF::are_connected(int p, int q)
{
    return do_find(p) == do_find(q);
}

void WeightedQuickUnionUF::do_union(int p, int q)
{
    int root_p = do_find(p);
    int root_q = do_find(q);

    if (root_p == root_q) {
        return;
    }

    // Smaller root will point to the bigger root
    if (size[root_p] < size[root_q]) {
        parent[root_p] = root_q;
        size[root_q] += size[root_p];
    }
    else {
        parent[root_q] = root_p;
        size[root_p] += size[root_q];
    }

    count -= 1;
}