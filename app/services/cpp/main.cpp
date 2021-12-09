#include <iostream>
#include "UnionFind.h"

using namespace std;

int main(void)
{
    UnionFind *uf = new UnionFind(15);
    std::cout << uf->get_count() << endl;
}