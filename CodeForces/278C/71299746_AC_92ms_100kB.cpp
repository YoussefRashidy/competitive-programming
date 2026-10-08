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
    int n , m ;
    cin >> n >> m ;
    DSU dsu(n+m+1) ;
    bool has_language = false ;
    for(int i = 1 ; i <= n ; i++) {
        int k ;
        cin >> k ;
        if(k > 0)
            has_language = true ;
        for(int j = 0 ; j < k ; j++) {
            int language ;
            cin >> language ;
            dsu.unite(i,language+n) ;
        }
    }

    unordered_set<int> components; 
    for(int i = 1 ; i <= n ; i++) {
        int parent = dsu.findSet(i) ;
        if(components.find(parent) == components.end()) {
            components.insert(parent) ;
        }
    }

    if(!has_language) {
        cout << components.size() << endl ;
    }
    else {
        cout << components.size() - 1 << endl ;
    }
}