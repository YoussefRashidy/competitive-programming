#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;

long long mod = 1e8 ;
long long  beautiful_arrangements(int i , int j , int m , int k , int n1 ,int n2 ,int k1 , int k2 , vector<vector<vector<vector<long long>>>>& memo) ;
int main() {
    int n1,n2,k1,k2 ;
    cin >> n1 >> n2 >> k1 >> k2 ;
    vector<vector<vector<vector<long long>>>> memo(n1+1,vector<vector<vector<long long>>>(n2+1,vector<vector<long long>>(k1+1,vector<long long>(k2+1,-1)))) ;
    long long max_arrangements = beautiful_arrangements(0,0,0,0,n1,n2,k1,k2,memo) ;
    cout << max_arrangements << endl ;
}

long long  beautiful_arrangements(int i , int j , int m , int k , int n1 ,int n2 ,int k1 , int k2 , vector<vector<vector<vector<long long>>>>& memo){
    if(i == n1 && j == n2)
        return 1 ;

    
    if(memo[i][j][m][k]!= -1)
        return memo[i][j][m][k] ;
    
    long long ch1 = 0 , ch2 = 0 ;
    ch1 = (m+1 <= k1 && i+1 <= n1) ? beautiful_arrangements(i+1,j,m+1,0,n1,n2,k1,k2,memo) % mod : 0 ;
    ch2 = (k+1 <= k2 && j+1 <= n2) ? beautiful_arrangements(i,j+1,0,k+1,n1,n2,k1,k2,memo) % mod : 0 ;

    return memo[i][j][m][k] = (ch1 + ch2) % mod ;
}