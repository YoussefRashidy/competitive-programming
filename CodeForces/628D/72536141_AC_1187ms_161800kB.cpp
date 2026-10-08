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

long long dp(int i ,int sum ,bool tight , int d , int m , string& a , vector<vector<vector<int>>>& memo ){
    if(i >= a.size())
        return sum == 0 ;
    if(memo[i][sum][tight] != -1)
        return memo[i][sum][tight] ;
    int en = tight ? a[i] - '0' : 9 ;
    long long ans = 0 ;
    if(i%2!=0){
        if(d > en)
            return memo[i][sum][tight]  = 0 ;
        memo[i][sum][tight] = dp(i+1,(sum*10+d)%m , tight&&d==en,d,m,a , memo);
        return memo[i][sum][tight] ;
    }
    for(int j = 0 ; j <= en ; j++){
        if(j == d ){
            continue;
        }
        ans= (ans + dp(i+1,(sum*10+j)%m , tight&&j==en,d,m,a , memo)) % mod ;
    }
    return ans ;
}
int main(){
    int d , m;
    cin >> m >> d ;
    string a , b ;
    cin >> a >> b ;
    vector<vector<vector<int>>> memo(2000,vector<vector<int>>(m,vector<int>(2,-1))) ;
    long long ans = dp(0,0,true,d,m,b , memo) ;
    for (auto& v : memo)
        for (auto& x : v)
            fill(x.begin(), x.end(), -1);   
    ans = (ans - dp(0,0,true,d,m,a , memo) + mod ) % mod  ;
    bool valid = true ;
    int sum = 0 ;
    for(int i = 0 ; i < a.size() ; i++){
        if(i % 2 != 0 && a[i] - '0' != d){
            valid = false ;
            break ;
        }
        if(i % 2 == 0 && a[i] - '0' == d){
            valid = false ;
            break ;
        }
        sum = (sum*10 + a[i] - '0') % m ;
    }
    if(valid && sum == 0)
        ans = (ans + 1) % mod ;
    cout <<  ans << endl ;
}