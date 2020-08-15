// this is for usage implementation of C++STL
#include <iostream>
#include <vector>
#include <set>
#include <map>

#include <algorithm>
using namespace std;
void printVector(vector<int> ar)
{
    for (int x : ar)
        cout << x << " ";
    cout << endl;
}
void Vector()
{
    vector<int> ar = {23, 22, 2, 1, 15, 3, 1636, 1};
    printVector(ar);

    sort(ar.begin(), ar.end());
    //O(logn)
    printVector(ar);

    //using binary search
    //checking id 22 is present
    if (binary_search(ar.begin(), ar.end(), 22))
        cout << "22 is present" << endl;
    else

        cout << "22is not present";
    ar.push_back(12);
    printVector(ar);
    ar.push_back(22);
    sort(ar.begin(), ar.end());

    //say we want to get to the 1st occurence of 22
    //you can also use auto for this
    vector<int>::iterator a = lower_bound(ar.begin(), ar.end(), 22); //>=
    vector<int>::iterator b = upper_bound(ar.begin(), ar.end(), 22); //>
    //iterator simply means a pointer
    //so to print it we need to use *a

    cout << "a = " << *a << " b = " << *b << endl; //22
    cout << b - a << endl;                         //O(1) this gives the count of 22
}
void printSet(set<int> S)
{
    for (int x : S)
        cout << x << " ";
    cout << endl;
}
void Set()
{
    //set maintains ascending order internally;
    //each operation is O(logn)

    set<int> S;
    S.insert(1);
    S.insert(3);
    S.insert(12);
    S.insert(11);
    S.insert(-1);
    printSet(S);
    // finding an element
    auto it = S.find(11);
    if (it != S.end())
        cout << "Found 11" << endl;

    //if element is not present it resturns the iterator to S.end()
    //now using lower_bound and upper_bound;

    auto a = S.lower_bound(3);
    auto b = S.upper_bound(3);
    //if upper_bound is not present it returns S.end()
    cout << "a: " << *a << " b: " << *b << endl;

    //erasing a no. also takes log(n)

    S.erase(11);
    printSet(S);
}

void Map()
{
    // mapping something to something in log(n)
    //a.find() or a.erase() also in log(n)
    map<int, int> M;
    M[1] = 10;  //1:10
    M[2] = 200; //2:200
}
int main()
{
    cout << "Vector" << endl;

    Vector();
    cout << "Set" << endl;
    Set();
}