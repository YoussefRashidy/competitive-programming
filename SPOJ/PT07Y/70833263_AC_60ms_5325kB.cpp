#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std ;
bool dfs(int vertex ,int parent,unordered_map<int, vector<int>>& adjacencyList , unordered_set<int> & visited) ;
int main() {
    unordered_map<int, vector<int>> adjacencyList ;
    int n , m ;
    cin >> n >> m ;

    for (size_t i = 0; i < m; i++)
    {
        int u,v ;
        cin >> u >> v ;
        adjacencyList[u].push_back(v) ;
        adjacencyList[v].push_back(u) ;
    }

    unordered_set<int> visited ;
    bool hasCycle = false ;
    hasCycle = dfs(1,-1,adjacencyList,visited) ;
    !hasCycle && visited.size() == n && m == (n-1) ? cout << "YES" : cout << "NO" ;
    
}

bool dfs(int vertex ,int parent,unordered_map<int, vector<int>>& adjacencyList , unordered_set<int> & visited) {
    visited.insert(vertex) ;
    for(int neighbour : adjacencyList[vertex]) {
        if(neighbour == parent) 
            continue ;
        if (visited.find(neighbour) != visited.end())
        {
            return true ;
        }
        if (dfs(neighbour,vertex,adjacencyList,visited)) {
            return true ;
        }
    }
    return false ;
}