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
    int times[n];
    for (int i = 0; i < n; i++)
    {
        cin >> times[i];
    }
    int ans = 0;
    int low = 0;
    int hig = 0;
    int time = 0;
    while (hig < n)
    {
        if (time + times[hig] <= t)
        {
            time += times[hig];
            hig++;
            ans = max(ans,hig-low);
        }
        else
        {
            time -= times[low];
            low++;
        }
    }
    cout << ans;
}