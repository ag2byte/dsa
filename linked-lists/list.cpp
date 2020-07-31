#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int elem, Node *next, Node *prev)
    {
        this->data = elem;
        this->next = next;
        this->prev = prev;
    }
};

class DLL
{
public:
    int size = 0;
    Node *head = NULL;
    Node *tail = NULL;

    void clear()
    {
        //empty the list
        Node *trav = head;

        while (trav != NULL)
        {
            Node *next = trav->next;
            trav->next = trav->prev = NULL;
            trav->data = NULL;
            trav = next;
        }
        head = tail = trav = NULL;
        size = 0;
    }
    int sizeOf()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void addLast(int elem)
    {
        if (isEmpty())
        {
            head = tail = new Node(elem, NULL, NULL);
        }
        else
        {
            tail->next = new Node(elem, head, NULL);
            tail = tail->next;
        }

        size++;
    }
    void addFirst(int elem)
    {
        if (isEmpty())
        {
            head = tail = new Node(elem, NULL, NULL);
        }
        else
        {
            head->prev = new Node(elem, head, NULL);
            head = head->prev;
        }

        size++;
    }
    int peekFirst()
    {
        if (isEmpty())
        {
            cout << "Empty list";
            return NULL;
        }
        else
            return head->data;
    }

    int peekLast()
    {
        if (isEmpty())
        {
            cout << "Empty list";
            return NULL;
        }
        else
            return tail->data;
    }

    void removeFirst()
    {
        if (!isEmpty())
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            size--;
        }
        else
        {
            cout << "List is empty";
        }
    }
    void removeLast()
    {
        if (!isEmpty())
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;

            delete temp;
            size--;
        }
        else
            cout << "List is empty";
    }

    void remove(int n)
    {
        if (head->data == n)
            removeFirst();
        else if (tail->data == n)
            removeLast();
        else
        {
            Node *trav = head;
            while (trav->data != n)
                trav = trav->next;
            trav->prev->next = trav->next;
            trav->next->prev = trav->prev;

            delete trav;
        }
    }

    void allNodes()
    {
        if (!isEmpty())
        {
            Node *trav = head;
            while (trav != NULL)
            {
                cout << trav->data << " ";
                trav = trav->next;
            }
        }
    }
};

int main()
{
    DLL a;
    a.addFirst(12);
    a.addFirst(13);
    a.addFirst(14);
    a.allNodes();
}