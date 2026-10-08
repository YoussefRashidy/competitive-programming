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

int dp(int l , int r , vector<int>& seq, vector<vector<int>>& memo){
    if(l > r)
        return 0 ;
    if(l == r)
        return 1 ;
        
    if(memo[l][r] != -1)
        return memo[l][r] ;

    int ans = INT_MAX ;
    if(seq[l] == seq[l+1])
        ans = 1+dp(l+2,r,seq,memo) ;
    else
        ans = 1 + dp(l+1,r,seq,memo) ;
    for(int k = l+2 ; k <= r ; k++){
        if(seq[l] == seq[k])
            ans = min(ans , dp(l+1,k-1 , seq , memo) + dp(k+1,r,seq,memo)) ;
    }
    memo[l][r] = ans ;
    return ans ;
}
int main(){
    int n ;
    cin >> n ;
    vector<int> seq(n);
    for(int i = 0 ; i < n ; i++)
        cin >> seq[i] ;

    vector<vector<int>> memo(n+1,vector<int>(n+1,-1)) ;
    cout << dp(0,n-1,seq,memo) << endl  ;
}