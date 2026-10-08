#include <iostream>
#include <algorithm>
using namespace std ;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l,r ;
    cin >> l >> r ;
    int maxValue = 0 ;
    for (int i = l; i <= r; i++)
    {
        for (int k = i+1; k <= r; k++)
        {
            maxValue = max(maxValue,i^k) ;
        }
    }
    cout << maxValue ;
    
}