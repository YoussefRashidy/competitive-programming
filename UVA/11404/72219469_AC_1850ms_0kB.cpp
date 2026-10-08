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
string dp(int l , int r , string& s, vector<vector<string>>& memo) {
    if(l > r)
        return string() ;
    if(l==r)
        return string(1,s.at(l)) ;
    
    if(memo[l][r] != "")
        return memo[l][r] ;

    if(s.at(l) == s.at(r))
        return memo[l][r] = s.at(l) + dp(l+1,r-1,s,memo) + s.at(r) ;
    else {
        string s1 = dp(l,r-1,s,memo) ;
        string s2 = dp(l+1,r,s,memo) ;
        if(s1.size() > s2.size())
            return memo[l][r] = s1 ;
        else if(s1.size() < s2.size())
            return memo[l][r] = s2 ;
        else
            return memo[l][r] = min(s1,s2) ;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s ;
    while(cin >> s){
        vector<vector<string>> memo(1001,vector<string>(1001,"")) ;
        cout << dp(0,s.size()-1,s,memo) << endl ;
    }
}