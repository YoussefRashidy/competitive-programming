#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        long long height[n];
        long long sums [n+1] ;
        long long max_step[n+1] ;
        sums[0] = 0 ;
        max_step[0] = 0 ;
        for (int i = 0; i < n; i++)
        {
            cin >> height[i];
            sums[i+1] = sums[i]+height[i] ;
            max_step[i+1] = max(max_step[i],height[i]) ;
        }
        

        long long ques[q];
        for (int i = 0; i < q; i++)
        {
            cin >> ques[i];
            long long lo = 0;
            long long hi = n;
            long long ans = -1;
            while (lo <= hi)
            {
                long long mid = lo + (hi - lo) / 2;
                if (max_step[mid] <= ques[i])
                {
                    ans = mid ;
                    lo = mid+1 ;
                }
                else
                {
                    hi = mid-1 ;
                }
            }
            cout << (ans==-1 ? 0 : sums[ans]) << " " ;
        }
        cout << '\n' ;
    }
}