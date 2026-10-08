#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct DSU {
    vector<int> parent , rank ;
    DSU(int n) {
        parent.resize(n+1) ;
        rank.resize(n+1) ;
        for(int i = 1 ; i <= n ; i++) {
            parent[i] = i ;
            rank[i] = 1 ;
        }
    }

    int findSet(int u) {
        if (parent[u] != u )
            parent[u] = findSet(parent[u]) ;
        return parent[u] ;
    }

    void unite(int u , int v) {
        if (findSet(u) == findSet(v))
            return ;
        
        int uParent = parent[u] ;
        int vParent = parent[v] ;
        int uRank = rank[uParent] ;
        int vRank = rank[vParent] ;

        if (uRank > vRank)
        {
            parent[vParent] = uParent ;
        }
        else if (vRank > uRank) 
            parent[uParent] = vParent ;
        else {
            parent[vParent] = uParent ;
            rank[uParent]++ ;
        }
    }


} ;
int main() {
    int n , m ;
    cin >> n >> m ;
    DSU dsu(n) ;
    for (size_t i = 0; i < m; i++)
    {
        int u,v ;
        cin >> u >> v ;
        dsu.unite(u,v) ;
    }

    vector<int> components ;
    for (size_t i = 1; i <= n; i++)
    {
        if (dsu.findSet(i) == i)
        {
            components.push_back(i) ;
        }
    }

    cout << components.size() - 1 << endl ;
    for (size_t i = 1; i < components.size(); i++)
    {
        cout << components[i-1] << " " << components[i] << endl ;
    }
    
    
    
    
}