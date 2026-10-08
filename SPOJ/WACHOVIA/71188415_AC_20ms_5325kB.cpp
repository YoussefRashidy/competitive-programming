#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

long long max_value(int i , int w , int max_weight ,vector<pair<int, int>> &bags,vector<vector<int>> &memo ) ;
int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int k , m ;
        cin >> k >> m ;
        vector<pair<int, int>> bags(m) ;
        for(int i =0 ;i< m ; i++) {
            cin >> bags[i].first >> bags[i].second ;
        }
        vector<vector<int>> memo(m+1, vector<int>(k+1, -1)) ;
        long long val = max_value(0,0,k,bags,memo) ;
        cout << "Hey stupid robber, you can get " << val << "." <<endl ;
    }
}

long long max_value(int i , int w , int max_weight ,vector<pair<int, int>> &bags,vector<vector<int>> &memo ){
    if(i >= bags.size())
        return 0 ;
    if(memo[i][w] != -1)
        return memo[i][w] ;
    
    long long take = LLONG_MIN , leave = LLONG_MIN ;

    if(w+bags[i].first <= max_weight)
        take =  max_value(i+1,w+bags[i].first , max_weight , bags , memo) + bags[i].second ;
    
    leave =  max_value(i+1,w , max_weight , bags , memo) ;

    return memo[i][w] = max(take,leave) ;
    
}