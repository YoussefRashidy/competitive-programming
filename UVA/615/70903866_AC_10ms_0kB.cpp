#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;


bool dfs(int node , unordered_map<int,vector<int>> &adjacenyList ,unordered_set<int>& visited ) ;

int main() {
    int k = 1 ;
    while (true)
    {
        unordered_map<int,vector<int>> adjacenyList ;
        unordered_set<int> nodes ;
        unordered_set<int> has_incoming_edges ;
        bool terminate = false ;
        while (true)
        {
            int u,v ;
            cin >> u >> v ;
            if(u==0 && v==0)
                break ;
            if(u<0 && v<0) {
                terminate = true ;
                break; 
            }

            nodes.emplace(u) ;
            nodes.emplace(v) ;
            adjacenyList[u].push_back(v) ;
            has_incoming_edges.emplace(v) ;
        }

        if(terminate)
            break;

        if(nodes.empty()) {
            cout << "Case " << k++ << " is a tree." << endl ;
            continue ;
        }

        if(nodes.size()-1 != has_incoming_edges.size()) {
            cout << "Case " << k++ << " is not a tree." << endl ;
            continue ;
        }

        int root = -1 ;
        for(int node : nodes) {
            if(has_incoming_edges.find(node) == has_incoming_edges.end() ) {
                root = node;
                break;
            }
        }

        unordered_set<int> visited ;
        bool res = dfs(root,adjacenyList,visited) ;
        if(!res || visited.size() != nodes.size()) {
            cout << "Case " << k++ << " is not a tree." << endl ;
        }
        else
            cout << "Case " << k++ << " is a tree." << endl ;

    }
    
    
}

bool dfs(int node , unordered_map<int,vector<int>> &adjacenyList ,unordered_set<int>& visited ) {
    visited.insert(node) ;
    for(int neighbor : adjacenyList[node]) {
        if(visited.find(neighbor) != visited.end()) {
            return false ;
        }
        if(!dfs(neighbor , adjacenyList , visited)) {
            return false ;
        }
    }
    return true ;
}