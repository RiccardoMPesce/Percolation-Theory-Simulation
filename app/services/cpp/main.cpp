#include <iostream>
#include "UF.h"

using namespace std;

int main(void)
{
    UnionFind *uf = new UnionFind(15);
    std::cout << uf->count() << endl;
}