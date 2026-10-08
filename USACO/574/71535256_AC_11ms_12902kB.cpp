#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include <iomanip>
#include <fstream>

using namespace std ;

long long dp(int t ,bool drank_water ,int a , int b , int max_t, vector<vector<long long>>& memo) ;
int main() {
    ifstream cin("feast.in");
    ofstream cout("feast.out");
    int t ,a , b;
    cin >> t >> a>> b;
    vector<vector<long long>> memo(t+1,vector<long long>(2,-1)) ;
    long long max_fullness = dp(0,false,a,b,t,memo) ;
    cout << max_fullness << endl ;
}

long long dp(int t ,bool drank_water ,int a , int b , int max_t, vector<vector<long long>>& memo) {
    if(t == max_t)
        return t ;
    if(memo[t][drank_water] != -1)
        return memo[t][drank_water] ;
    long long ch1,ch2,ch3 ;
    ch1 = (t+a <= max_t) ? dp(t+a,drank_water ,a,b,max_t,memo) : t ;
    ch2 = (t+b <= max_t) ? dp(t+b,drank_water ,a,b,max_t,memo) : t ;
    ch3 = (!drank_water) ? dp(t/2,true ,a,b,max_t,memo) : t ;
    
    return memo[t][drank_water] = max(ch1,max(ch2,ch3)) ;
} 