// using hashmap in c++ implementing seperate chaining

// does not work currently, somework to be done

#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable
{
private:
    static const int hashGroup = 10; // no of groups
    list<pair<int, string>> table[hashGroup];

public:
    bool isEmpty()
    {
        int sum;
        for (int i = 0; i < hashGroup; i++)
            sum += table[i].size();
        if (sum == 0)
            return true;
        else
            return false;
    }
    int hashFunction(int key)
    {
        // since we have only 10 groups we want to have value in [0-9]
        return key % hashGroup;
    }
    void insertItem(int key, string value)
    {
        int hashValue = hashFunction(key);
        cout << "hashvalue = " << hashValue << endl;

        auto cell = table[hashValue]; // table at the current hashvalue
        auto bitr = begin(cell);      // beginner iterator
        bool keyExists = false;
        for (; bitr != end(cell); bitr++)
        {
            if (bitr->first == key)
            {
                keyExists = true;
                bitr->second = value;
                // key exists, value replaced
                cout << "KEY exists, value replaced";
                break;
            }
        }
        if (!keyExists)
            cell.emplace_back(key, value);
    }
    void removeItem(int key)
    {
        int hashValue = hashFunction(key);
        auto cell = table[hashValue]; // table at the current hashvalue
        auto bitr = begin(cell);      // beginner iterator
        bool keyExists = false;
        for (; bitr != end(cell); bitr++)
        {
            if (bitr->first == key)
            {
                keyExists = true;
                bitr = cell.erase(bitr);
                // key exists, value deleted

                cout << "Item removed";
                break;
            }
        }
        if (!keyExists)
            cout << "Item not found";
    }

    void printTable()
    {
        for (int i = 0; i < hashGroup; i++)
        {
            if (table[i].size() == 0)
            {
                continue;
            }
            auto bitr = table[i].begin();
            for (; bitr != table[i].end(); bitr++)
                cout << "KEY:" << bitr->first << " VALUE:" << bitr->second << endl;
        }
    }
};

int main()
{
    /* code */
    HashTable HT;
    if (!HT.isEmpty())
        cout << "well done" << endl;
    else
        cout << "code error" << endl;

    HT.insertItem(132, "A");
    // HT.insertItem(142, "B");
    HT.insertItem(114, "C");
    HT.insertItem(243, "D");
    // HT.insertItem(1163, "E");
    // HT.insertItem(134, "f");

    HT.printTable();
    return 0;
}
