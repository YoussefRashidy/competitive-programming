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

long long dp(int l ,int r,int current_pair,int n ,int m , int k,vector<int>&a, vector<long long>&prefix_sum){
    if(current_pair > k)
        return 0 ;
    if(r>n)
        return LLONG_MIN ;
    
    long long ch1 = 0 , ch2 = 0 ;
    if(r-l+1 < m)
        ch1 = dp(l,r+1,current_pair,n,m,k,a,prefix_sum) ;
    else 
        ch1 = (prefix_sum[r] - prefix_sum[l-1]) + dp(r+1,r+1,current_pair+1,n,m,k,a,prefix_sum);
    if(n-r >= m)
        ch2 = dp(r+1,r+1,current_pair,n,m,k,a,prefix_sum) ;
    else if (n-r == m)
        ch2 = (prefix_sum[n] - prefix_sum[r])  ;
    return max(ch1, ch2);
}

long long dp_(int i , int j , int m , int k , vector<long long>& prefix_sum , vector<vector<long long>>& memo){
    if(j ==0)
        return 0 ;
    if(i < j*m)
        return LLONG_MIN ;
    if(memo[i][j] != -1)
        return memo[i][j] ;
    long long ch1 = 0 , ch2 = 0 ;
    ch1 = dp_(i-1,j,m,k,prefix_sum,memo) ;
    ch2 = (prefix_sum[i] - prefix_sum[i-m]) + dp_(i-m,j-1,m,k,prefix_sum,memo) ;
    return memo[i][j] = max(ch1, ch2);
}
int main(){
    int n , m ,k ;
    cin >> n >> m >> k ;
    vector<int> a(n+1,0) ;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i] ;
    vector<long long> prefix_sum(n+1,0) ;
    for(int i = 1 ; i <= n ; i++)
        prefix_sum[i] = prefix_sum[i-1] + a[i] ;
    vector<vector<long long>> memo(n+1,vector<long long>(k+1,-1)) ;
    cout << dp_(n,k,m,k,prefix_sum,memo) << endl ;
}