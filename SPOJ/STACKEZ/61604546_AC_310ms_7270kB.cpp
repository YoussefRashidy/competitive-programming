#include <iostream>
#include <stack>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int op;
    stack<int> st;
    int number;
    for (int i = 0; i < n; i++)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> number;
            st.push(number);
            break;
        case 2:
            if (st.empty())
            {
                break;
            }
            st.pop();
            break;
        case 3:
            if (st.empty())
            {
                cout << "Empty!" << "\n";
                break;
            }
            cout << st.top() << "\n";
            break;
        default:
            break;
        }
    }
}