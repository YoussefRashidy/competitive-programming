#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

long long knapsack(int i , int w ,vector<vector<long long>>& memo , int max_weight , vector<long long> &values,vector<int>& weights) ;
int main() {
    int n , w ;
    cin >> n >> w ;
    vector<vector<long long>> memo(n+1,vector<long long>(w+1, -1)) ;
    vector<long long> values(n+1) ;
    vector<int> weights(n+1) ;
    for (int i = 1; i <= n; i++)
    {
        int w ,v ;
        cin >> w >> v ;
        weights[i] = w ;
        values[i] = v ;
    }

    long long value = knapsack(1,0,memo,w,values,weights) ;
    cout << value << endl ;
    
}

long long knapsack(int i , int w ,vector<vector<long long>>& memo , int max_weight , vector<long long> &values,vector<int>& weights) {
    if(i >= values.size())
        return 0 ;

    if(memo[i][w]!= -1)
        return memo[i][w] ;
    
    long long ch1 = LONG_LONG_MIN  , ch2 = LONG_LONG_MIN ;
    if(w+weights[i] <= max_weight)
        ch1 = values[i]+knapsack(i+1,w+weights[i],memo,max_weight,values,weights) ;
    
    ch2 = knapsack(i+1,w,memo,max_weight,values,weights) ;
    return memo[i][w] = max(ch1 , ch2) ;
    
}