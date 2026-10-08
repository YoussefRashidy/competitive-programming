#include <iostream>
#include <stack>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    stack <char> st ;
    for (int i = 0; i < input.length(); i++)
    {
        char c = input.at(i);
        if (!st.empty() && st.top() == c )
        {
            st.pop();
        } 
        else
        {
            st.push(c) ;
        }
    }
    cout << (st.empty() ? "Yes" : "No") ;
}