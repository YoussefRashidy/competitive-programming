#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long int stones[n];
    multiset<long long int> sortedStones;
    for (int i = 0; i < n; i++)
    {
        cin >> stones[i];
        sortedStones.emplace(stones[i]);
    }
    long long int sums[n + 1];
    sums[0] = 0;
    for (int i = 0; i < n; i++)
    {
        sums[i + 1] = sums[i] + stones[i];
    }
    long long int sortedSums[n + 1];
    sortedSums[0] = 0 ;
    auto it = sortedStones.begin();
    for (int i = 0; i < n; i++)
    {
        sortedSums[i + 1] = sortedSums[i] + *it;
        it++;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int op;
        cin >> op;
        switch (op)
        {
        case 1:
        {
            int l, r;
            cin >> l >> r;
            long long int answer = sums[r] - sums[l-1];
            cout << answer << '\n';
            break;
        }
        case 2:
        {
            int l, r;
            cin >> l >> r;
            long long int answer = sortedSums[r] - sortedSums[l-1];
            cout << answer << '\n';
            break;
        }

        default:
            break;
        }
    }
}