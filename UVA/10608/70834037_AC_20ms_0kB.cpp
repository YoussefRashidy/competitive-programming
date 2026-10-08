#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct DSU {
    vector<int> parent ;
    vector<int> rank ;
    vector<int> size ;

    DSU(int n) {
        parent.resize(n+1) ;
        rank.resize(n+1) ;
        size.resize(n+1) ;
        for (size_t i = 1; i <= n; i++) {
            parent[i] = i ;
            rank[i] = 1 ;
            size[i] = 1 ;
        }
    }

    int findSet(int u) {
        if (parent[u] != u)
        {
            parent[u] = findSet(parent[u]) ;
        }
        return parent[u] ;
    }

    void unite(int u , int v) {
        if (findSet(u) == findSet(v))
            return ;
        int uRep = findSet(u) ;
        int vRep = findSet(v) ;

        if (rank[uRep] > rank[vRep]){
            parent[vRep] = uRep ; 
            size[uRep] += size[vRep] ;
        }
        else if (rank[uRep] < rank[vRep]){ 
            parent[uRep] = vRep ; 
            size[vRep] += size[uRep] ;
        }
        else {
            parent[vRep] = uRep ;
            rank[uRep] ++ ;
            size[uRep] += size[vRep] ;
        }
        
    }

} ;
int main(){
    int t ;
    cin >> t ;
    for (size_t i = 0; i < t; i++)
    {
        int n , m;
        cin >> n >> m ;
        DSU dsu(n) ;
        for(int j = 0 ; j < m ; j++) {
            int u , v ;
            cin >> u >> v ;
            dsu.unite(u,v) ;
        }
        int maxSize = 0 ;
        for (int j = 1; j <= n; j++)
        {
            maxSize = maxSize > dsu.size[j] ? maxSize : dsu.size[j] ;
        }
        cout << maxSize << endl ;
    }
    
}