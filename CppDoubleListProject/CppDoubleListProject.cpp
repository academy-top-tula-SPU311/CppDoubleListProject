#include <iostream>

struct Node
{
    int value;
    Node* next{};
    Node* prev{};
};

struct List
{
    Node* front{};
    Node* back{};
    int size{};
};

void ListPuhsBack(List& list, int value);
void ListPuhsFront(List& list, int value);
void ListPrint(List list);

int ListPopBack(List& list);
int ListPopFront(List& list);

int main()
{

    List list;
    ListPuhsBack(list, 100);
    ListPuhsBack(list, 200);
    ListPuhsBack(list, 300);

    ListPrint(list);
    std::cout << "\n";

    ListPuhsFront(list, 400);
    ListPuhsFront(list, 500);
    ListPuhsFront(list, 600);

    ListPrint(list);
}

void ListPuhsBack(List& list, int value)
{
    Node* nodeNew = new Node;
    nodeNew->value = value;
    
    if (!list.size)
    {
        list.front = list.back = nodeNew;
    }
    else
    {
        nodeNew->prev = list.back;
        list.back->next = nodeNew;
        list.back = nodeNew;
    }
    list.size++;
}

void ListPuhsFront(List& list, int value)
{
    Node* nodeNew = new Node;
    nodeNew->value = value;

    if (!list.size)
    {
        list.front = list.back = nodeNew;
    }
    else
    {
        nodeNew->next = list.front;
        list.front->prev = nodeNew;
        list.front = nodeNew;
    }
    list.size++;
}

void ListPrint(List list)
{
    Node* nodeCurrent{ list.front };
    while (nodeCurrent)
    {
        std::cout << nodeCurrent->value << "\n";
        nodeCurrent = nodeCurrent->next;
    }
}

int ListPopBack(List& list)
{
    int value = list.back->value;

    if (list.size > 1)
    {
        list.back = list.back->prev;
        delete list.back->next;
        list.back->next = nullptr;
    }
    else
    {
        delete list.back;
        list.back = list.front = nullptr;
    }
    list.size--;
    return value;
}

int ListPopFront(List& list)
{
    int value = list.front->value;

    if (list.size > 1)
    {
        list.front = list.front->next;
        delete list.front->prev;
        list.front->prev = nullptr;
    }
    else
    {
        delete list.front;
        list.back = list.front = nullptr;
    }
    list.size--;
    return value;
}
