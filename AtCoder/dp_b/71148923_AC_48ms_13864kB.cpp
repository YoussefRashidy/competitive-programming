#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;


long long cost(int i , vector<int> & heights , vector<long long> & memo , int n , int k)  ;

int main() {
    int n , k;
    cin >> n >> k;
    vector<int> heights(n+1) ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> heights[i] ;
    }
    vector<long long> memo(n+1,-1) ;
    long long min_cost = cost(1,heights,memo,n,k) ;
    cout << min_cost << endl ;
}

long long cost(int i , vector<int> & heights , vector<long long> & memo , int n , int k) {
    if(i == n)
        return 0 ;
    if(memo[i] != -1)
        return memo[i] ;

    long long ch = LONG_LONG_MAX  ;

    for(int j = 1 ; j <= k ; j++ ) {
        long long min_cost ;
        if(i+j <= n)
            min_cost = abs(heights[i] - heights[i+j]) + cost(i+j , heights , memo , n , k) ;
        else 
            min_cost = LONG_LONG_MAX ;
        ch = min(ch , min_cost) ;
    }



    return memo[i] = ch ;
}