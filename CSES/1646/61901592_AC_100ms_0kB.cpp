#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    int values[n+1];
    values[0] = 0 ;
    for (int i = 0; i < n; i++)
    {
        cin >> values[i+1];
    }
    long long  sums[n + 1];
    sums[0] = 0;
    for (int i = 0; i < n; i++)
    {
        sums[i + 1] = sums[i] + values[i+1];
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        long long sum = sums[b] - sums[a-1];
        cout << sum << '\n';
    }
}