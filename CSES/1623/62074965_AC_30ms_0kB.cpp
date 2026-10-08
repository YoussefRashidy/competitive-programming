#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <numeric>
#include <cmath>
#include <limits.h>
using namespace std;
using ll = long long;
ll lowest = LLONG_MAX;

vector<ll> apples;
vector<pair<vector<ll>, vector<ll>>> pairs;
void appleGroups(int i, vector<ll> &group1, vector<ll> &group2);
ll sum(vector<ll> &vec);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int apple;
        cin >> apple;
        apples.emplace_back(apple);
    }
    vector<ll> group1;
    vector<ll> group2;

    appleGroups(0, group1, group2);
    // for (auto &&i : pairs)
    // {
    //     ll current = abs(sum(i.first)-sum(i.second)) ;
    //     lowest = min(lowest,current) ;
    // }
    cout << lowest;
}

void appleGroups(int i, vector<ll> &group1, vector<ll> &group2)
{
    if (i == apples.size())
    {
        lowest = min(lowest,abs(sum(group1)-sum(group2))) ;
        return;
    }
    group1.push_back(apples[i]);
    appleGroups(i + 1, group1, group2);
    group1.pop_back();
    group2.push_back(apples[i]);
    appleGroups(i + 1, group1, group2);
    group2.pop_back();
}
ll sum(vector<ll> &vec)
{
    ll sum = 0;
    for (auto &&i : vec)
    {
        sum += i;
    }
    return sum;
}