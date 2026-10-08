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

long long dp(int l, int r , bool turn , vector<int>& v ,vector<vector<vector<long long>>>& memo){
    if(l > r)
        return 0 ;
    if(memo[l][r][turn] != LLONG_MIN)
        return memo[l][r][turn] ;
    int sign = (turn) ? 1 : -1 ;
    if(turn)
        return memo[l][r][turn] = max(dp(l+1,r,!turn,v,memo) + sign*v[l] , dp(l,r-1,!turn , v, memo ) + sign*v[r]) ;
    else
        return memo[l][r][turn] = min(dp(l+1,r,!turn,v,memo) + sign*v[l] , dp(l,r-1,!turn , v, memo ) + sign*v[r]) ;
}

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i] ;
    }
    vector<vector<vector<long long>>> memo(n+1,vector<vector<long long>> (n+1, vector<long long>(2,LLONG_MIN))) ;
    cout << dp(0,n-1,true,v,memo) << endl ;
}