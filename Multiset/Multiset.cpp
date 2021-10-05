#include <iostream>
#include "Multiset.h"
#include "Pair.h"
Multiset::Multiset()
{
    head = nullptr;
    nodeCount = 0;
}

Multiset::~Multiset()
{
    Node* p;
    p = head;

    while (p != nullptr)
    {
        Node* n = p->next;
        delete p;
        p = n;
    }
    nodeCount = 0;
}
void Multiset::readFromFile(std::ifstream& rff) {
    int tmp;
    rff >> tmp;
    while (rff)
    {
        this->insert(tmp);
        rff >> tmp; 
    }
}
void Multiset::print() {
    Node* p(head);
    std::cout << "Элементы множества:\n";
    while (p != nullptr)
    {
        std::cout << "Элемент: " << p->data << ", " << "Количество: "<<p->elemCount<<'\n';
        p = p->next;
    }
}
void Multiset::insert(const int& value)
{
    if (head == nullptr || value < head->data)
        addToHead(value);
    else
    {
        if (value == head->data)
            head->elemCount++;
        else
        {
            Node* prev = head;

            Node* cur = head->next;
            while (cur != nullptr && value > cur->data)
            {
                prev = cur;
                cur = cur->next;
            }
            if (cur == nullptr)
                addAfterNode(value, prev);
            else
            {
                if (value == cur->data)
                    cur->elemCount++;
                else
                    addAfterNode(value, prev);
            }
        }
    }
}
void Multiset::addToHead(const int& value) {
    Node* p = new Node;
    nodeCount++;
    p->data = value;
    p->next = head;
    p->elemCount++;
    head = p;
}
void Multiset::addAfterNode(const int& value, Node* nn) {
    if (nn != nullptr) {
        Node* p = new Node;
        nodeCount++;
        p->data = value;
        p->next = nn->next;
        p->elemCount++;
        nn->next=p;
    }
}
bool Multiset::isEmpty() {
    return this->head == nullptr;
}
MultisetPair::~MultisetPair()
{
    Node* p;
    p = head;

    while (p != nullptr)
    {
        Node* n = p->next;
        delete p;
        p = n;
    }
    nodeCount = 0;
}
void MultisetPair::print() {
    Node* p(head);
    std::cout << "Элементы множества:\n";
    while (p != nullptr)
    {
        std::cout << "Элемент: (" << p->data.first() << "," << p->data.second() << "), " << "количество: " << p->elemCount << '\n';
        p = p->next;
    }
}
void MultisetPair::addToHead(const Pair& value) {
    Node* p = new Node;
    nodeCount++;
    p->data = value;
    p->next = head;
    head = p;
}
void MultisetPair::addAfterNode(const Pair& value, Node* nn) {
    if (nn != nullptr) {
        Node* p = new Node;
        nodeCount++;
        p->data = value;
        p->next = nn->next;
        nn->next=p;
        
    }
}
void MultisetPair::directMultiplication(Multiset& A, Multiset& B) {
    Multiset::Node* pa,*pb;
    Node* ptr=head;
    Pair p;
    pa = A.head;
    pb = B.head;
    while (pa != nullptr) {
        while (pb != nullptr){
            p.makePair(pa->data, pb->data);
            if (ptr == nullptr) {
                addToHead(p);
                ptr = head;
                ptr->elemCount = pa->elemCount * pb->elemCount;
            }
            else {
                addAfterNode(p, ptr);
                ptr = ptr->next;
                ptr->elemCount = pa->elemCount * pb->elemCount; 
            }
            pb = pb->next;
        }
        pa = pa->next;
        pb = B.head;
    }
}