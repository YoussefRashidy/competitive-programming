#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int first = l ;
        int second = l*2 ;
        if (second > r)
        {
            cout << "-1 -1\n" ;
        }
        else
        {
            cout << first << ' ' << second << '\n' ;
        }
        
    }
}