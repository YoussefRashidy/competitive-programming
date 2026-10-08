#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
using namespace std;

const int mod = 1e9 + 7 ;
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

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    int n , k ;
    cin >> n >> k ;
    DSU dsu(n) ;
    for(int i = 0 ; i < n-1 ; i++){
        int u , v , c ;
        cin >> u >> v >> c ;
        if(c == 0) {
            dsu.unite(u,v) ;
        }
    }
    
    unordered_set<int> components; 
    for(int i = 1 ; i <= n ; i++) {
        int parent = dsu.findSet(i) ;
        if(components.find(parent) == components.end()) {
            components.insert(parent) ;
        }
    }

    long long answer = 1 ;
    for(int i =0 ; i < k ; i++) {
        answer = (answer*n) % mod ;
    }

    for(int component : components) {
        answer = (answer - (power(dsu.size[component], k))+ mod) % mod ;
    }

    cout << answer << endl ;
}