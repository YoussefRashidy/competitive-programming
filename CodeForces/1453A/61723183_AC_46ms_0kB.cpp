#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int n, m;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int toBeCanc = 0;
        set<int> bottom;
        set<int> left;
        cin >> n;
        cin >> m;
        for (int k = 0; k < n; k++)
        {
            int number;
            cin >> number;
            bottom.emplace(number);
        }
        for (int k = 0; k < m; k++)
        {
            int number;
            cin >> number;
            left.emplace(number);
        }
        for (auto it = bottom.begin(); it != bottom.end(); it++)
        {
            if (left.find(*it) != left.end())
            {
                toBeCanc++;
            }
        }
        cout << toBeCanc << '\n';
    }
    
}