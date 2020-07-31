#include "list.cpp";
#include <iostream>
using namespace std;
// Stack implementation using Linked Lists
class Stack
{
private:
    DLL s;

public:
    void push(int n)
    {
        s.addFirst(n);
    }
    void top()
    {
        s.peekFirst();
    }
    void pop()
    {
        s.removeFirst();
    }
    bool isEmpty()
    {
        return s.isEmpty();
    }
    void display()
    {
        s.allNodes();
    }
};
// int main()
// {
//     Stack s;
//     s.push(12);
//     s.push(13);
//     s.push(14);
//     s.display();
//     cout << endl;
//     s.top();
//     s.pop();
//     cout << endl;
//     s.display();
//
