#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include <iomanip>
#include <fstream>
#include<queue>
#include<climits>

using namespace std ;

void print_path(int node , vector<int> & parent) ;
int main() {
    int n , m ;
    cin >> n >> m ;
    vector<vector<int>> graph(n+1) ;
    for (int i = 0; i < m; i++)
    {
        int u , v; 
        cin >> u >> v ;
        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }
    vector<int> shortest_path(n+1,INT_MAX) ;
    vector<int> parent(n+1,-1) ;
    vector<bool> visited(n+1) ;
    queue<int> q ;
    q.push(1) ;
    visited[1] = true ;
    shortest_path[1] = 1 ;
    parent[1] = 1 ;
    while (!q.empty()) {
        int u = q.front() ; q.pop() ;
        for(int v : graph[u]) {
            if(visited[v])
                continue; 
            visited[v] = true ;
            q.push(v) ;
            shortest_path[v] = shortest_path[u] + 1 ;
            parent[v] = u ;
        }
    }
    if(shortest_path[n] != INT_MAX) {
        cout << shortest_path[n]  << endl ;
        print_path(n,parent) ;
    }
    else 
        cout << "IMPOSSIBLE" << endl ;
    
}

void print_path(int node , vector<int> & parent) {
    if(node != parent[node])
        print_path(parent[node] , parent) ;
    cout << node << " " ;
}