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
    cin >> n ;
    string s1,s2 ;
    cin >> s1 >> s2 ;
    DSU dsu(26) ;
    vector<pair<char,char>> changes ;
    int change_count = 0 ;
    for(int i = 0 ; i < n ; i++) {
        int c1 = s1[i] - 'a' ;
        int c2 = s2[i] - 'a' ;
        if(dsu.findSet(c1) != dsu.findSet(c2)) {
            dsu.unite(c1,c2) ;
            changes.push_back({s1[i],s2[i]}) ;
            change_count++ ;
        }
    }

    cout << change_count << endl ;
    for(auto change : changes) {
        cout << change.first << " " << change.second << endl ;
    }
}