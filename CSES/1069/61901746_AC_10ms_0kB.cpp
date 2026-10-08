#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string DNA ;
    cin >>DNA ;
    int lo = 0 , hi = 1 ;
    int longest = 1 ;
    while (hi < DNA.size())
    {
        if (DNA.at(hi) != DNA.at(lo))
        {
            lo++;
        }
        else
        {
            hi++;
            longest = max(longest,hi-lo) ;
        }
    }
    cout << longest ;
    
    
}