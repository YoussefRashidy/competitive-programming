#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int prices[n];
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    int q;
    cin >> q;
    int money[q];
    for (int i = 0; i < q; i++)
    {
        cin >> money[i];
    }
    sort(prices, prices + n);
    for (int i = 0; i < q; i++)
    {
        int number = upper_bound(prices, prices + n, money[i]) - prices;
        cout << number << '\n';
    }
}