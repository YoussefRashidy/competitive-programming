#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m ;
    cin >> n >> m ;
    int array1[n] ;
    int array2[m] ;
    int greater[m] ;
    for (int i = 0; i < n; i++)
    {
        cin >> array1[i] ;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> array2[i] ;
    }
    sort(array1,array1+n) ;
    for (int i = 0; i < m; i++)
    {
        greater[i] = upper_bound(array1,array1+n,array2[i])-array1 ;
    }
    for (int i = 0; i < m; i++)
    {
        cout << greater[i] << " " ;
    }
    
    
    
     
}