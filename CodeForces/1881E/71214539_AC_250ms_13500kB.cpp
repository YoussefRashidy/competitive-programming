#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;

const int INF = 1e9;

int block_sequence(int i , int n , vector<int> &sequence , vector<int> & memo) ;
int main() {
    int t ;
    cin >> t;
    while(t--) {
        int n ;
        cin >> n;
        vector<int> sequence(n) ;
        vector<int> memo(n,-1) ;
        for(int i = 0; i < n; i++) {
            cin >> sequence[i];
        }
        cout << block_sequence(0,n,sequence ,memo) << endl ;
    }
}

int block_sequence(int i , int n , vector<int> &sequence , vector<int>& memo) {
    if(i == n)
        return 0 ;
    if(i > n)
        return INF ;
    if(memo[i]!= -1)
        return memo[i] ;
    int ch1 ;
    int ch2 ;
    ch1 = 1 + block_sequence(i+1,n,sequence,memo) ;
    ch2 = block_sequence(i+sequence[i]+1 , n , sequence,memo) ;

    return memo[i] = min(ch1,ch2) ;
}