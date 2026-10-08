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
long long dp(int l , int r , vector<int>& a , vector<long long>& prefix_sum, vector<vector<long long>>& memo){
    if(l>=r)
        return 0 ;
    if(memo[l][r] != -1)
        return memo[l][r] ;
    long long ans = LLONG_MAX ;
    for(int i = l ; i < r ; i++){
        ans = min(ans , dp(l,i,a,prefix_sum,memo) + dp(i+1,r,a,prefix_sum,memo) + (prefix_sum[r] - prefix_sum[l-1])) ;
    }
    return memo[l][r] = ans ;
}
int main(){
    int n ;
    cin >> n ;
    vector<int> a(n) ;
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i] ;
    }
    vector<long long> prefix_sum(n+1,0) ;
    for(int i = 1 ; i <= n ; i++){
        prefix_sum[i] = prefix_sum[i-1] + a[i-1] ;
    }
    vector<vector<long long>> memo(n+1,vector<long long>(n+1,-1)) ;
    cout << dp(1,n,a,prefix_sum,memo) << endl  ;
}