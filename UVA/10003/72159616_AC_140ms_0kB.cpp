#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
#include<set>
#include <iomanip>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;
long long dp(int l , int r ,int length,vector<int>& stick ,vector<vector<long long>>& memo) {
    if (r - l <= 1)
        return 0;
    
    if(memo[l][r] != -1)
        return memo[l][r] ;
    long long ans = LLONG_MAX ;
    
    

    for(int i = l+1 ; i < r ; i++){
        ans = min(ans , dp(l,i,stick[i]-stick[l],stick,memo) + dp(i,r,stick[r]-stick[i],stick,memo) + length) ;
    }
   
    return memo[l][r] = ans ;
}
int main(){
    while(true) {
        int l ;
        cin >> l ;
        if(l ==0)
            break ;
        int n;
        cin >> n ;
        vector<int> a(n+2) ;  
        a[0] = 0 ;
        a[n+1] = l ;
        for(int i = 1 ; i <= n ; i++) {
            cin >> a[i] ;
        }
        vector<vector<long long>> memo(n+2,vector<long long>(n+2,-1)) ;
        cout <<"The minimum cutting is " <<dp(0,n+1,l,a,memo) <<"." << endl ;
    }
}