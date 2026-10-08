#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

long long mod = 1e9 + 7 ;
long long paths(int i , int j ,int n,int m,vector<vector<char>> &grid,vector<vector<int>> &memo ) ;
int main() {
    int n , m ;
    cin >> n >> m ;
    vector<vector<char>> grid(n, vector<char>(m)) ;
    vector<vector<int>> memo(n, vector<int>(m, -1)) ;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> grid[i][j] ;
        }
    }

    
    long long num_paths = paths(0,0,n,m,grid,memo) ;

    cout << num_paths << endl ;

}



long long paths(int i , int j ,int n,int m,vector<vector<char>> &grid,vector<vector<int>> &memo ){
    if(i == n-1 && j == m-1) 
        return 1 ;
    if(memo[i][j] != -1)
        return memo[i][j] ;

    long long ch1 = 0 , ch2 = 0 ;

    if(i+1 < n && grid[i+1][j] != '#')
        ch1 = paths(i+1,j,n,m,grid,memo) ;
    if(j+1 < m && grid[i][j+1] != '#')
        ch2 = paths(i,j+1,n,m,grid,memo) ;

    return memo[i][j] = ((ch1 % mod) + (ch2 % mod)) % mod ;


}