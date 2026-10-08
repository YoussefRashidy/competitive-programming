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
    cin >> t ;
    while(t--)
    {
        int n ;
        cin >> n ;
        int copy = n ;
        while(copy % 2 != 0)
        {
            copy-- ;
        }
        cout << gcd(copy,copy/2) << '\n' ;
    }
}