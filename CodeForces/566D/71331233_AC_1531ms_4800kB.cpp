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
    int n , q ;
    cin >> n >> q ;
    DSU dsu(n) ;
    DSU next(n+1) ;
    for(int i = 0 ; i < q; i++) {
        int type , u,v;
        cin >> type >> u >> v ;
        switch (type)
        {
        case 1:
            dsu.unite(u,v) ;
            break;
        case 2:
            {
                int j = next.findSet(u) ;
                while(j < v) {
                dsu.unite(j,j+1) ;
                next.parent[j] = next.findSet(j+1) ;
                j = next.findSet(j) ;
            }
            break;}
        case 3:
            if(dsu.findSet(u) == dsu.findSet(v))
                cout << "YES\n" ;
            else
                cout << "NO\n" ;
            break;
        default:
            break;
        }
    }
}