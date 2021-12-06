#include "WeightedUF.h"

WeightedUF::WeightedUF(int n)
{
    if (n < 0) {
        throw std::invalid_argument("n must be equal or greater than 0");
    }
    this->count = n;
    this->parent = std::vector<int>(n);
    this->size = std::vector<int>(n);
    
    for (int i = 0; i < n; i++) {
        this->parent[i] = i;
        this->size[i] = 0;
    }
}

WeightedUF::~WeightedUF()
{
    ;
}

int WeightedUF::do_find(int p)
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

bool WeightedUF::are_connected(int p, int q)
{
    return this->do_find(p) == this->do_find(q);
}

void WeightedUF::do_union(int p, int q)
{
    int root_p = this->do_find(p);
    int root_q = this->do_find(q);

    if (root_p == root_q) {
        return;
    }

    // Smaller root will point to the bigger root
    if (this->size[root_p] < this->size[root_q]) {
        this->parent[root_p] = root_q;
        this->size[root_q] += this->size[root_p];
    }
    else {
        this->parent[root_q] = root_p;
        this->size[root_p] += this->size[root_q];
    }
}