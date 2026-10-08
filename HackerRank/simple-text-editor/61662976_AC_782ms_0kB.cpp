#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int op;
    cin >> n;
    string current = "";
    stack<string> undo;
    for (int i = 0; i < n; i++)
    {
        cin >> op;
        switch (op)
        {
        case 1:
        {
            undo.push(current);
            string app;
            cin >> app;
            current.append(app);
            break;
        }
        case 2:
        {
            undo.push(current);
            int k;
            cin >> k;
            current.erase(current.size() - k, k);
            break; 
        }
        case 3:
        {
            int k;
            cin >> k;
            cout << current.at(k - 1) << '\n';
            break;
        }
        case 4:
        {
            current = undo.top();
            undo.pop();
            break;
        }

        default:
            break;
        }
    }
}