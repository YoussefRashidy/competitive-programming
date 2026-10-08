#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int x1;
    queue<int> que;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> x1;
        if (!vec.empty() && x1 == 1)
        {
            que.push(vec.back());
        }
        vec.push_back(x1);
    }
    que.push(x1);
    cout << que.size() << '\n';
    int size = que.size();
    for (int i = 0; i < size; i++)
    {
        cout << que.front() << " ";
        que.pop();
    }
}