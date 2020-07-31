#include <bits/stdc++.h>
using namespace std;
bool bracketCheck(string s)
{

    stack<char> S;
    for (char ch : s)
    {
        if (ch == '(')
            S.push(ch);
        else if (ch == ')')
            if (!S.empty() && S.top() == '(')
                S.pop();
            else
            {
                return false;
            }
    }
    if (S.empty())
        return true;
    else
    {
        return false;
    }
}
int main()
{
    string s = "(())(())";
    cout << bracketCheck(s);
}