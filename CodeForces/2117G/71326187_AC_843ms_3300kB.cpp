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
    vector<long long> weight ;
    DSU(int n) {
        parent.resize(n+1) ;
        rank.resize(n+1,0) ;
        size.resize(n+1,1) ;
        weight.resize(n+1,LONG_MAX) ;
        for(int i = 0 ; i <= n ; i++)
            parent[i] = i ;
    }

    int findSet(int x) {
        if(parent[x] != x)
            parent[x] = findSet(parent[x]) ;
        return parent[x] ;
    }

    void unite(int x , int y , long long w) {
        int xParent = findSet(x) ;
        int yParent = findSet(y) ;
        int xRank = rank[xParent] ;
        int yRank = rank[yParent] ;
        if(xParent == yParent)
            return ;
        if(xRank > yRank) {
            parent[yParent] = xParent ;
            size[xParent] += size[yParent] ;
            weight[xParent] = min(min(weight[xParent],weight[yParent]),w) ;
        }
        else if (xRank < yRank) {
            parent[xParent] = yParent ;
            size[yParent] += size[xParent] ;
            weight[yParent] = min(min(weight[yParent],weight[xParent]),w) ;
        }
        else {
            parent[yParent] = xParent ;
            size[xParent] += size[yParent] ;
            rank[xParent]++ ;
            weight[xParent] = min(min(weight[xParent],weight[yParent]),w) ;
        }
    }
} ;

struct Edge {
    int u,v;
    long long w ; 
} ;

int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int n ,m ;
        cin >> n >> m ;
        vector<Edge> edges(m) ;
        for(int i = 0 ; i < m ; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w ;
        }
        sort(edges.begin(), edges.end(), [](Edge a , Edge b) {
            return a.w < b.w ;
        }) ;
        DSU dsu(n) ;
        long long min_weight = LLONG_MAX ;
        for(auto edge : edges) {
            if(dsu.findSet(edge.u) != dsu.findSet(edge.v)) {
                dsu.unite(edge.u,edge.v,edge.w) ;

                if(dsu.findSet(1) == dsu.findSet(n)) {
                    min_weight = min(min_weight , edge.w + dsu.weight[dsu.findSet(1)]) ;
                }
            }
        }

        cout << min_weight << endl ;
    }
}