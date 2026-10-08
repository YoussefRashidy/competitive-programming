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
long long dp(int l , int r , vector<int>& a,vector<vector<long long>> &memo){
    if(l==r)
        return 0 ;
    if(memo[l][r] != -1)
        return memo[l][r] ;
    long long ch1 = (a[r]-a[l]) + dp(l+1,r,a,memo) ;
    long long ch2 = (a[r]-a[l]) + dp(l,r-1,a,memo) ;

    return memo[l][r] = min(ch1,ch2) ;
}
int main(){
    int n ;
    cin >> n ;
    vector<int> a(n) ;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i] ;
    sort(a.begin(),a.end());
    vector<vector<long long>> memo(n+1,vector<long long> (n+1,-1)) ;
    cout << dp(0,n-1,a,memo) << endl ;
}