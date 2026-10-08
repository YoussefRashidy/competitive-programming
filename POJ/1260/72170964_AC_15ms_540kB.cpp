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

long long dp(int l , int r , vector<pair<long long ,long long>> perls , vector<long long>& prefix_count , vector<vector<long long>>& memo) {
    if(r>=perls.size()){
        return (prefix_count[r]-prefix_count[l-1] + 10)*perls[r-1].second ;
    }
    
    long long ans = LLONG_MAX ;
    if(memo[l][r] != -1){
        return memo[l][r] ;
    }
    ans = min((prefix_count[r]-prefix_count[l-1] + 10 )*perls[r-1].second + dp(r+1,r+1,perls,prefix_count,memo) , dp(l,r+1,perls,prefix_count,memo)) ;
    memo[l][r] = ans ;
    return ans ;
}

int main(){
    int t ;
    cin >> t;
    while(t--){
        int n ;
        cin >> n ;
        vector<pair<long long, long long>> pearls(n);
        for(int i = 0; i < n; i++){
            cin >> pearls[i].first >> pearls[i].second;
        }
        vector<long long> prefix_count(n+1,0) ;
        for(int i = 1 ; i <= n ; i++){
            prefix_count[i] = prefix_count[i-1] + pearls[i-1].first ;
        }
        vector<vector<long long>> memo(n+1,vector<long long>(n+1,-1)) ;
        cout << dp(1,1,pearls,prefix_count,memo) << endl;
    }
}