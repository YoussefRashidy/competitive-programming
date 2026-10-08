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

long long dp(int l , int r , string & s , vector<vector<long long>>& memo){
    if(l>=r)
        return 0 ;
    if(memo[l][r]!=-1)
        return memo[l][r] ;
    if(s.at(l)==s.at(r))
        return memo[l][r] = dp(l+1,r-1,s,memo) ;
    else{
        long long ch1 = 1 + dp(l+1,r-1,s,memo) ;
        long long ch2 = 1 + dp(l,r-1,s,memo) ;
        long long ch3 = 1 + dp(l+1,r,s,memo) ;
        return memo[l][r] = min(ch1,min(ch2,ch3)) ;
    }
}

int main(){
    int t ;
    cin >> t ;
    int i = 1 ;
    while(t--){
        string s ;
        cin >> s ;
        int n = s.size() ;
        vector<vector<long long>> memo(n+1,vector<long long>(n+1,-1)) ;
        cout << "Case " << i++ <<": " << dp(0,n-1,s,memo) << endl ;
    } 
}