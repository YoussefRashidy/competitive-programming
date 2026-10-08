#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

void dfs(int node ,vector<vector<int>>& adjecencyList , vector<bool>& visited) ;
int main() {
    int n , m ;
    cin >> n >> m ;
    
    vector<vector<int>> adjecencyList(n + 1) ;
    vector<bool> visited(n+1)  ;
    for(int i = 0 ; i < m ; i++) {
        int a , b ;
        cin >> a >> b ;
        adjecencyList[a].push_back(b) ;
        adjecencyList[b].push_back(a) ;
    }

    if(m != n) {
        cout << "NO" << endl ;
        return 0 ;
    }

    dfs(1,adjecencyList,visited) ;

    for(int i = 1 ; i < n+1 ; i++) {
        if(!visited[i]) {
            cout << "NO" << endl ;
            return 0 ;
        }
    }
    cout << "FHTAGN!" << endl ;
}

void dfs(int node ,vector<vector<int>>& adjecencyList , vector<bool>& visited) {
    visited[node] = true ;
    for(int neighbor: adjecencyList[node]) {
        if(!visited[neighbor])
            dfs(neighbor,adjecencyList,visited) ;
    }
}