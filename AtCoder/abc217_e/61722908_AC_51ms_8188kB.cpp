#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    int n;
    int x;
    deque<int> de;
    multiset<int> se;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> q;
        switch (q)
        {
        case 1:
        {
            int x;
            cin >> x;
            de.emplace_back(x);
            break;
        }
        case 2:
        {
            int elem;
            if (!se.empty())
            {
                elem = *se.begin();
                se.erase(se.begin());
            }
            else
            {
                elem = de.front();
                de.pop_front();
            }
            cout << elem << '\n';
            break;
        }
        case 3:
        {
           while (!de.empty())
           {
                se.emplace(de.front());
                de.pop_front();
           }
           
            break;
        }
        default:
            break;
        }
    }
}