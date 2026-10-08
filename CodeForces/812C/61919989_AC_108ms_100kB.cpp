#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll total_cost(const vector<int> &a, int k)
{
    vector<ll> costs;
    for (int i = 0; i < a.size(); ++i)
    {
        costs.push_back(a[i] + (ll)(i + 1) * k);
    }
    sort(costs.begin(), costs.end());
    ll sum = 0;
    for (int i = 0; i < k; ++i)
    {
        sum += costs[i];
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int left = 0, right = n;
    int ans_k = 0;
    ll ans_cost = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        ll cost = total_cost(a, mid);
        if (cost <= s)
        {
            ans_k = mid;
            ans_cost = cost;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << ans_k << " " << ans_cost << '\n';
    return 0;
}