#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;


long long cost(int i , vector<int> & heights , vector<long long> & memo , int n)  ;

int main() {
    int n ;
    cin >> n;
    vector<int> heights(n+1) ;
    for(int i = 1 ; i <= n ; i++) {
        cin >> heights[i] ;
    }
    vector<long long> memo(n+1,-1) ;
    long long min_cost = cost(1,heights,memo,n) ;
    cout << min_cost << endl ;
}

long long cost(int i , vector<int> & heights , vector<long long> & memo , int n) {
    if(i == n)
        return 0 ;
    if(memo[i] != -1)
        return memo[i] ;

    long long ch1 = LONG_LONG_MAX , ch2 = LONG_LONG_MAX ;

    if(i+1 <= n) {
        ch1 = cost(i+1 , heights,memo,n) + abs(heights[i] - heights[i+1]) ;
    }

    if(i+2 <= n) {
        ch2 = cost(i+2 , heights,memo,n) + abs(heights[i] - heights[i+2]) ;
    }

    return memo[i] = min(ch1, ch2) ;
}