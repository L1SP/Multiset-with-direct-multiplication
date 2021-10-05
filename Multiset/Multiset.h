#pragma once
#include "Pair.h"
#include <fstream>
class Multiset
{
    friend class MultisetPair;
    struct Node
    {
        int data;
        int elemCount;
        Node* next;
        Node() : data(0), elemCount(0), next(nullptr) {};
    };
    int nodeCount;
    Node* head;
    void addToHead(const int& value);
    void addAfterNode(const int& value, Node* nn);

public:
    Multiset();
    ~Multiset();
    void insert(const int& value);
    void print();
    bool isEmpty();
    void readFromFile(std::ifstream& rff);
};
class MultisetPair {
    struct Node
    {
        Pair data;
        int elemCount;
        Node* next;
        Node() : data(Pair(0,0)), elemCount(0), next(nullptr) {};
    };
    int nodeCount;
    Node* head;
    void addToHead(const Pair& value);
    void addAfterNode(const Pair& value, Node* nn);
public:
    MultisetPair() : head(nullptr), nodeCount(0) {};
    ~MultisetPair();
    void print();
    void directMultiplication(Multiset& A, Multiset& B);
};

