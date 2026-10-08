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

struct Edge {
    int u ,v ,w ;
    Edge(int u , int v , int w) : u(u) , v(v) , w(w) {}
} ;

int main() {
    int n , m ;
    cin >> n >> m ;
    vector<Edge> edges ;
    for(int i = 0 ; i < m ; i++) {
        int u , v , w ;
        cin >> u >> v >> w ;
        edges.push_back(Edge(u , v , w)) ;
    }

    sort(edges.begin() , edges.end() , [](Edge &a , Edge &b) {
        return a.w < b.w ;
    }) ;

    DSU dsu(n) ;
    long long weight = 0 ;
    for (int i = 0; i < m; i++)
    {
        Edge &min_edge = edges[i] ;
        if(dsu.findSet(min_edge.u) != dsu.findSet(min_edge.v))
        {
            dsu.unite(min_edge.u,min_edge.v) ;
            weight= weight + min_edge.w ;
        }
    }

    cout << weight << endl ;
    
}

