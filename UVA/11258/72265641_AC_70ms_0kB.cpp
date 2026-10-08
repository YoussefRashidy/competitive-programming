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

long long dp(int l , int r , string& s , vector<vector<long long>>& memo){
    if(r==s.size())
        return 0 ;
    if(r==l && s.at(r)=='0')
        return 0 + dp(r+1,r+1,s,memo) ;
    if(memo[l][r] != -1)
        return memo[l][r] ;
    long long ch1 = 0 , ch2 = 0 ;
    long long x = stoll(s.substr(l,r-l+1)) ;
    if(x < INT_MAX){
        ch1 = dp(l,r+1,s,memo) ;
        ch2 = dp(r+1,r+1,s,memo) + stoll(s.substr(l,r-l+1)) ;
    } 
    else 
        ch1 =  stoll(s.substr(l,r-l)) + dp(r,r,s,memo) ;
    return memo[l][r] = max(ch1,ch2) ;
}
int main(){
    int n ;
    cin >> n ;
    while(n--){
        string s ;
        cin >> s ;
        vector<vector<long long>> memo(s.size()+1,vector<long long>(s.size()+1,-1)) ;
        cout << dp(0,0,s,memo) << endl ;
    }
}