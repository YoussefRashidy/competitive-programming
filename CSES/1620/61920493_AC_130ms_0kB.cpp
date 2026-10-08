#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    int machines[n];
    for (int i = 0; i < n; i++)
    {
        cin >> machines[i];
    }
    long long low = 1;
    long long high = 1e18;
    while (low < high)
    {
        long long mid = low + (high - low) / 2;
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            total += mid / machines[i];
            if (total >=t)
            {
                break;
            }
            
        }
        if (total >= t)
        {
            high = mid;
        }
        else if (total < t)
        {
            low = mid + 1;
        }
    }
    cout << low;
}