#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

long long mod = 1e9 + 7 ;
long long paths(int i , int j ,int n,vector<vector<char>> &grid,vector<vector<int>> &memo ) ;
int main() {
    int n ;
    cin >> n ;
    vector<vector<char>> grid(n, vector<char>(n)) ;
    vector<vector<int>> memo(n, vector<int>(n, -1)) ;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> grid[i][j] ;
        }
    }

    if(grid[0][0] == '*' || grid[n-1][n-1] == '*') {
    cout << 0 << '\n';
    return 0;
    }
    
    long long num_paths = paths(0,0,n,grid,memo) ;

    cout << num_paths << endl ;

}



long long paths(int i , int j ,int n,vector<vector<char>> &grid,vector<vector<int>> &memo ){
    if(i == n-1 && j == n-1) 
        return 1 ;
    if(memo[i][j] != -1)
        return memo[i][j] ;

    long long ch1 = 0 , ch2 = 0 ;

    if(i+1 < n && grid[i+1][j] != '*')
        ch1 = paths(i+1,j,n,grid,memo) ;
    if(j+1 < n && grid[i][j+1] != '*')
        ch2 = paths(i,j+1,n,grid,memo) ;

    return memo[i][j] = ((ch1 % mod) + (ch2 % mod)) % mod ;


}