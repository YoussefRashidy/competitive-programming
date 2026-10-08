#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;

const int INF = 1e9;
int sleep_scheulde(int i , int t ,int n , int l , int r , int h , vector<int> &sleep , vector<vector<int>>& memo) ;
int main() {
    int n ,h , l,r ;
    cin >> n >> h >> l >> r ;
    vector<int> sleep(n) ;
    for(int i = 0 ; i < n ; i++) {
        cin >> sleep[i] ;
    }
    vector<vector<int>> memo(n+1,vector<int>(h+1,-1)) ;
    int max_sleep = sleep_scheulde(0,0,n,l,r,h,sleep,memo) ;
    cout << max_sleep << endl ;
}

int sleep_scheulde(int i , int t ,int n , int l , int r , int h , vector<int> &sleep , vector<vector<int>>& memo) {
    if(i >= n)
        return 0 ;
    if(memo[i][t] != -1)
        return memo[i][t] ;
    
    int ch1 = INT_MIN , ch2 = INT_MIN ;

    if(l<= (sleep[i] +  t) % h &&  (sleep[i] + t) % h <= r)
        ch1 = 1 + sleep_scheulde(i+1 , (t+ sleep[i]) % h , n , l , r , h , sleep , memo) ;
    else 
        ch1 = sleep_scheulde(i+1 , (t+ sleep[i]) % h , n , l , r , h , sleep , memo) ;
    
    if(l <= (sleep[i] - 1 + t) % h  && (sleep[i] - 1 + t) % h <= r)
        ch2 = 1 + sleep_scheulde(i+1 , (t+ sleep[i] - 1) % h , n , l , r , h , sleep , memo) ;
    else 
        ch2 = sleep_scheulde(i+1 , (t+ sleep[i] - 1) % h , n , l , r , h , sleep , memo) ;

    return memo[i][t] = max(ch1 , ch2) ;
}