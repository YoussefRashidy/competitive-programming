#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include <iomanip>
#include <fstream>
#include<queue>
#include<climits>
#include<bitset>
#include<set>

using namespace std ;

long long backtrack(int i , long long product , long long x , vector<vector<int>> & a){
    if(i == a.size() && product == x)
        return 1 ;
    if(i == a.size())
        return 0 ;
    long long count  = 0 ;
    for(int j = 0 ; j < a[i].size() ; j++) {
        if(product*a[i][j] > x) {
            continue;
        }
        product*= a[i][j] ;
        count+= backtrack(i+1,product,x,a) ;
        product/=a[i][j] ;
    }
    return count ;
}
int main() {
    int n ;
    long long x ;
    cin >> n >> x ;
    vector<vector<int>> v(n) ;
    for(int i = 0 ; i < n ; i++) {
        int l ;
        cin >> l ;
        for(int j = 0 ; j < l ; j++) {
            int a ;
            cin >> a ;
            v[i].push_back(a) ;
        }
    }
    long long count = backtrack(0,1,x,v) ;
    cout << count << endl ;
    
}