#include <iostream>
#include "WeightedQuickUnionUF.h"

using namespace std;

int main(void)
{
    WeightedQuickUnionUF *uf = new WeightedQuickUnionUF(1500);
    std::cout << uf->get_count() << endl;
}