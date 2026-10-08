#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;



int dp_vertex(int vertex ,vector<vector<int>>& graph , vector<int>& memo ) {
    if(graph[vertex].empty())
        return 0 ;
    if(memo[vertex] !=-1)
        return memo[vertex] ;
    
    int longest_path = 0 ;
    for(int neighbor: graph[vertex]) {
        longest_path = max(longest_path ,1+ dp_vertex(neighbor,graph,memo)) ;
    }
    return memo[vertex] = longest_path ;
}

int dp(vector<vector<int>>& graph,vector<int>& memo) {
    int longest_path = 0 ;
    for(int i = 1 ; i < graph.size() ; i++) {
        longest_path = max(longest_path, dp_vertex(i,graph,memo)) ;
    }
    return longest_path ;
}

int main() {
    int n , m ;
    cin >> n >> m ;
    vector<vector<int>> graph(n+1) ;
    for(int i = 0 ; i < m ; i++) {
        int u , v ;
        cin >> u >> v ;
        graph[u].push_back(v) ;
    }
    vector<int> memo(n+1,-1) ;  
    cout << dp(graph , memo) << endl ; 
}

