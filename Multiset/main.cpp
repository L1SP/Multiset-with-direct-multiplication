#include <iostream>
#include <fstream>
#include "Pair.h"
#include "Multiset.h"
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    Multiset* A = new Multiset;
    Multiset* B = new Multiset;
    MultisetPair ans;
    ifstream rfA("A.txt");
    ifstream rfB("B.txt");
    A->readFromFile(rfA);
    B->readFromFile(rfB);
    A->print();
    B->print();
    ans.directMultiplication(*A, *B);
    ans.print();
    rfA.close();
    rfB.close();
    delete A;
    delete B;
    return 0;
}