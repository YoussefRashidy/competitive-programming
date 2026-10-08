#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int labels[n];
    for (int i = 0; i < n; i++)
    {
        cin >> labels[i];
    }
    int m;
    cin >> m;
    int juicey[m];
    for (int i = 0; i < m; i++)
    {
        cin >> juicey[i];
    }
    int presum[n+1] ;
    presum[0] = 0 ;
    for (int i = 0; i < n; i++)
    {
        presum[i+1]=presum[i]+labels[i] ;
    }
    for (int i = 0; i < m; i++)
    {
        int lowBound = lower_bound(presum,presum+n,juicey[i])-presum;
        cout << lowBound <<'\n' ;
    }
    
    
}