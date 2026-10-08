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
bool isPalindrome(string& s , int l , int r , vector<vector<char>>& memo){
    if(l>=r)
        return memo[l][r] = 1 ;
    if(memo[l][r]!=-1)
        return memo[l][r] ;
    if(s.at(l)==s.at(r))
        return memo[l][r] = isPalindrome(s,l+1,r-1,memo) ;
    else
        return memo[l][r] = 0 ;
}
int dp(int l , int r , string& s , vector<vector<int>>& memo , vector<vector<char>>& isPal){
    if(l>r)
        return 0 ;

    if(l==r)
        return memo[l][r] = 1 ;
    
    if(memo[l][r]!=-1)
        return memo[l][r] ;
    
    int ans = dp(l,r-1,s,memo,isPal) + dp(l+1,r,s,memo,isPal) - dp(l+1,r-1,s,memo,isPal) + isPal[l][r] ;
    return memo[l][r] = ans ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s ;
    cin >> s ;
    int q;
    cin >> q ;
    vector<vector<int>> memo(s.size()+1,vector<int>(s.size()+1,-1)) ;
    vector<vector<char>> isPal(s.size()+1,vector<char>(s.size()+1,-1)) ;
    for (int l = 0; l < s.size(); l++) {
        for (int r = l; r < s.size(); r++) {
            isPalindrome(s, l, r, isPal);
        }
    }

    dp(0,s.size()-1,s,memo,isPal) ;     
    while(q--){
        int l , r ; 
        cin >> l >> r ;
        cout << memo[l-1][r-1] << '\n' ;
    }
}