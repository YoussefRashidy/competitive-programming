#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

void dfs(int node , vector<int> &parents , vector<bool> &visited , stack<int>& path ) ;

int main() {
    int t ;
    cin >> t ;
    for (int i = 0; i < t; i++) {
        int n ;
        cin >> n ;
        vector<int> parents(n+1)  ;
        vector<bool> isLeaf(n+1 , true) ;
        for (int i = 1; i < n+1; i++)
        {
            int p ;
            cin >> p ;
            parents[i] = p ;
            if(p!=i)
                isLeaf[p] = false ;
        }

        vector<int> leaves ;
        for (int i = 1; i < n+1; i++)
        {
            if(isLeaf[i])
                leaves.push_back(i) ;
        }

        cout << leaves.size() << endl ;
        vector<bool> visited(n+1) ;
        for(int leaf : leaves) {
            stack<int> path ;
            dfs(leaf,parents,visited,path) ;
            cout << path.size() << endl ;
            int size = path.size() ;
            for(int i = 0; i < size; i++) {
                cout << path.top() << " " ;
                path.pop() ;
            }
            cout << endl ;
        }        
        cout << endl ;

    }
    
}

void dfs(int node , vector<int> &parents , vector<bool> &visited , stack<int>& path ) {
    visited[node] = true ;
    path.push(node) ;
    if (!visited[parents[node]])
    {
        dfs(parents[node] , parents,visited,path) ;
    }
    
}