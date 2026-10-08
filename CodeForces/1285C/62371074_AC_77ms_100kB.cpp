#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
vector<pair<long long, long long>> divisors(long long x);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long x;
    cin >> x;
    vector<pair<long long, long long>> divs = divisors(x);
    long long maxElemnt = LONG_LONG_MAX;
    pair<long long, long long> target;
    for (auto &&pr : divs)
    {
        if (lcm(pr.first, pr.second) == x)
        {
            if (max(pr.first, pr.second) < maxElemnt)
            {
                maxElemnt = max(pr.first, pr.second);
                target = pr;
            }
        }
    }
    cout << target.first << ' ' << target.second;
}

vector<pair<long long, long long>> divisors(long long x)
{
    vector<pair<long long, long long>> divs;
    for (int i = 1; 1LL*i * i <= x; i++)
    {
        if (x % i == 0)
        {
            divs.push_back({i, 1LL*x / i});
        }
    }
    return divs ;
}