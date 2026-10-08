#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int op;
    queue<int> que;
    int number;
    for (int i = 0; i < n; i++)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> number;
            que.push(number);
            break;
        case 2:
            if (que.empty())
            {
                break;
            }
            que.pop();
            break;
        case 3:
            if (que.empty())
            {
                cout << "Empty!" << "\n";
                break;
            }
            cout << que.front() << "\n";
            break;
        default:
            break;
        }
    }
}