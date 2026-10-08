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

int mod = 1e9 + 7 ;
int sum_range(int l , int r , string& s){
    int ans = 0 ;
    for(int i = l ; i <= r ; i++){
        ans = (ans + (s.at(i) - '0')) % mod ;
    }
    return ans ;
}


int dp(int l , int r , string& s, vector<vector<int>>& memo){
    if(l >= r)
        return 1 ;
        

    if(memo[l][r] != -1)
        return memo[l][r] ;
    int ans = 1 ;
    int leftSum = 0 ;
    for(int i = l ; i < r ; i++){
        leftSum = (leftSum + (s.at(i) - '0')) ;
        int rightSum = 0 ;
        for(int j = r ; j > i ; j--){
            rightSum = (rightSum + (s.at(j) - '0')) ;
            if(leftSum == rightSum){
                ans += dp(i + 1, j - 1, s, memo);
                ans %= mod;
            }
        }
        
    }
    memo[l][r] = ans ;
    return ans ;
}
int main(){
    int t ;
    cin >> t ;
    while(t--){
        string s ;
        cin >> s ;
        vector<vector<int>> memo(s.size()+1,vector<int>(s.size()+1,-1)) ;
        cout << dp(0,s.size()-1,s,memo) << endl ;
    }
}