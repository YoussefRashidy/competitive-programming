#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

void dfs(vector<vector<int>> & graph , vector<bool>& visited , int vertex) ;
vector<long long> bellmanford(int source ,vector<vector<pair<long long , int>>>& graph , int v , int m , bool& positive_cycle , vector<bool>& reachable) ;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , m ;
    cin >> n >> m ;
    vector<vector<pair<long long , int>>> graph (n+1);
    vector<vector<int>> reverse_graph (n+1) ;
    for (int i = 0; i < m; i++)
    {
        int u , v ;
        long long w ;
        cin >> u >> v >> w ;
        graph[u].push_back({w,v}) ;
        reverse_graph[v].push_back(u) ;
    }
    vector<bool> reachable(n+1,false) ;
    dfs(reverse_graph,reachable,n) ;
    bool postive_cycle = false ;
    vector<long long> longestPath = bellmanford(1,graph,n,m,postive_cycle,reachable) ;
    if(postive_cycle) {
        cout << -1 << endl ;
    } else {
        cout << longestPath[n] << endl ;
    }
}

void dfs(vector<vector<int>> & graph , vector<bool>& visited , int vertex) {
    visited[vertex] = true ;
    for(int neighbor : graph[vertex]) {
        if(!visited[neighbor]) {
            dfs(graph, visited, neighbor) ;
        }
    }
}

vector<long long> bellmanford(int source ,vector<vector<pair<long long , int>>>& graph , int v , int m , bool& positive_cycle , vector<bool>& reachable) {
    vector<long long> longestPath(v+1,LLONG_MIN) ;
    longestPath[source] = 0 ; 
    for(int i = 1 ; i < graph.size()  ; i++) {
        for(int j = 1 ; j < v +1 ; j++) {
            for(auto [weight , destination] : graph[j]) {
                if(longestPath[j] == LLONG_MIN)
                    continue;
                if(weight + longestPath[j] > longestPath[destination]) {
                    longestPath[destination] = weight + longestPath[j] ;
                }
            }
        }
    }
    for(int j = 1 ; j < v +1 ; j++) {
            for(auto [weight , destination] : graph[j]) {
                if(longestPath[j] == LLONG_MIN)
                    continue;
                if(weight + longestPath[j] > longestPath[destination]) {
                    if(reachable[destination]) {
                        positive_cycle = true ;
                        break;

                    }
                }
            }
    }
    return longestPath ;

}