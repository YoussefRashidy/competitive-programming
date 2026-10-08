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
#include <string>
using namespace std;



long long dp(int i,int rem,bool tight, const string& r , vector<vector<vector<long long>>>& memo){
    if(rem == 0)
        return 1 ;
    if(i == r.size())
        return 1 ;
    if(memo[i][rem][tight] != -1)
        return memo[i][rem][tight] ;
    int en = (tight) ? r.at(i) - '0' : 9 ;
    long long ans = 0 ;
    for(int j = 0 ; j <= en ; j++){
        ans += dp(i+1,(j == 0) ? rem : rem - 1, tight && (j == en) , r, memo) ;
    }
    return memo[i][rem][tight] = ans ;
}
int main(){
    int t ;
    cin >> t ;
    while(t--){
        long long l , r ;
        cin >> l >> r ;
        vector<vector<vector<long long>>> memo(20,vector<vector<long long>>(4,vector<long long>(2,-1))) ;
        long long ans = dp(0,3,true,to_string(r), memo) ;
        memo = vector<vector<vector<long long>>>(20,vector<vector<long long>>(4,vector<long long>(2,-1))) ;
        ans -= dp(0,3,true,to_string(l-1), memo) ;
        cout << ans << endl ;
    }
}