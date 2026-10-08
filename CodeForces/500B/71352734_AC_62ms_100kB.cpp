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
    vector<vector<char>> A(n, vector<char>(n)) ;
    vector<int> permutation(n) ;
    DSU dsu(n-1) ;
    for(int i = 0 ; i < n ; i++) {
        cin >> permutation[i] ;
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> A[i][j] ;
            if(A[i][j] == '1') {
                dsu.unite(i , j) ;
            }
        }
    }

    unordered_map<int, vector<int>> components ;
    for(int i =0 ; i <n ; i++) {
        components[dsu.findSet(i)].push_back(i) ;
    }

    vector<int> result(n) ;
    for(auto&[root , indices] : components) {
        vector<int> values ;
        for(int index : indices) {
            values.push_back(permutation[index]) ;
        }
        sort(values.begin() , values.end()) ;
        sort(indices.begin() , indices.end()) ;
        for(int i = 0 ; i < indices.size() ; i++) {
            result[indices[i]] = values[i] ;
        }
    }

    for(int i = 0 ; i < n ; i++) {
        cout << result[i] << " " ;
    }
    cout << endl ;

    
    
}