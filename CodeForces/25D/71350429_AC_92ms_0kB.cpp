#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
using namespace std;

struct DSU{
    vector<int> parent ;
    vector<int> rank ;
    vector<int> size ;
    DSU(int n) {
        parent.resize(n+1) ;
        rank.resize(n+1,0) ;
        size.resize(n+1,1) ;
        for(int i = 0 ; i <= n ; i++)
            parent[i] = i ;
    }

    int findSet(int x) {
        if(parent[x] != x)
            parent[x] = findSet(parent[x]) ;
        return parent[x] ;
    }

    void unite(int x , int y) {
        int xParent = findSet(x) ;
        int yParent = findSet(y) ;
        int xRank = rank[xParent] ;
        int yRank = rank[yParent] ;
        if(xParent == yParent)
            return ;
        if(xRank > yRank) {
            parent[yParent] = xParent ;
            size[xParent] += size[yParent] ;
        }
        else if (xRank < yRank) {
            parent[xParent] = yParent ;
            size[yParent] += size[xParent] ;
        }
        else {
            parent[yParent] = xParent ;
            size[xParent] += size[yParent] ;
            rank[xParent]++ ;
        }
    }

    
} ;


int main() {
    int n ;
    cin >> n  ;
    vector<pair<int,int>> edges ;
    for(int i = 0 ; i < n-1 ; i++) {
        int u , v ;
        cin >> u >> v ;
        edges.push_back({u,v}) ;
    }
    vector<pair<int,int>> remaining_edges ;
    DSU dsu(n) ;
    for(int i = 0 ; i< n-1; i++) {
        auto[u,v] = edges[i] ;
        if(dsu.findSet(u) != dsu.findSet(v)) 
            dsu.unite(u,v) ;
        else 
            remaining_edges.push_back(edges[i]) ;
    }
    
    vector<pair<int,int>> required_edges ;
    for(int i =2 ; i <= n ; i++) {
        if(dsu.findSet(i) != dsu.findSet(1)) {
            required_edges.push_back({1,i}) ;
            dsu.unite(1,i) ;
        }
    }

    cout << required_edges.size() << endl ;
    for(int i = 0 ; i < required_edges.size() ; i++) {
        auto[U,V] = remaining_edges[i]  ;
        auto[x,y] =  required_edges[i] ;
        cout << U << " " << V << " " << x << " " << y << endl ;
    }

    
    
}