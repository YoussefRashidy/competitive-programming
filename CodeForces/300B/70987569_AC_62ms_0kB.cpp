#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

void dfs(int node ,vector<vector<int>>& adjecencyList , vector<bool>& visited , vector<int>& component) ;
int main() {
    int n , m ;
    cin >> n >> m ;
    vector<vector<int>> adjecencyList(n + 1) ;
    vector<bool> visited(n+1)  ;
    vector<int> singles ;
    vector<vector<int>> doubles ;
    vector<vector<int>> triples ;
    for(int i = 0 ; i < m ; i++) {
        int a , b ;
        cin >> a >> b ;
        adjecencyList[a].push_back(b) ;
        adjecencyList[b].push_back(a) ;
    }

    for (int i = 1; i < n+1; i++)
    {
        vector<int> component ;
        if(!visited[i]){
            dfs(i ,adjecencyList , visited , component ) ;
            if(component.size() == 1)
                singles.push_back(component[0]);
            else if (component.size() == 2)
                doubles.push_back(component) ;
            else if (component.size() == 3)
                triples.push_back(component) ;
            else {
                cout << -1 << endl ;
                return 0;
            }
        }
    }

    if(doubles.size() > singles.size() || (singles.size() - doubles.size()) % 3 != 0) {
        cout << -1 << endl ;
        return 0 ;
    }

    for(int i = 0 ; i < doubles.size() ; i++) {
        doubles[i].push_back(singles[i]) ;
        triples.push_back(doubles[i]) ;
    }

    for (int i = doubles.size(); i < singles.size(); i+=3)
    {
        vector<int> component ;
        component.reserve(3);
        for (int j = 0; j < 3; j++)
        {
            component.push_back(singles[i+j]);
        }
        triples.push_back(component) ;
    }
    for(vector<int> team : triples) {
        for(int player : team ){
            cout << player << " " ; 
        }
        cout << endl ;
    }

    
    
}

void dfs(int node ,vector<vector<int>>& adjecencyList , vector<bool>& visited , vector<int>& component) {
    visited[node] = true ;
    for(int neighbor: adjecencyList[node]) {
        if(!visited[neighbor])
            dfs(neighbor,adjecencyList,visited,component) ;
    }
    component.push_back(node) ;
}