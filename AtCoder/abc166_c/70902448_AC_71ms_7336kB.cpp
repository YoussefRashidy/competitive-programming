#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
    int n , m ;
    cin >> n >> m ;
    vector<vector<int>> roads(n+1)  ;
    vector<int> elevation(n+1) ;
    for (int i = 1; i < n+1; i++) {
       cin >> elevation[i] ;
    }
    
    for (int i = 0; i < m; i++) {
        int u,v ;
        cin >> u >> v ;
        roads[u].push_back(v) ;
        roads[v].push_back(u) ;
    }

    queue<int> obs ;
    vector<bool> visited(n+1) ;
    int counter = 0 ; 
    for (int i = 1; i < n+1; i++)
    {
        if (!visited[i])
        {
            obs.push(i) ;
            visited[i] = true ;
            while (!obs.empty()) {
                bool good_obs = true ;
                int vertex = obs.front() ; obs.pop() ;
                visited[vertex] = true ;
                for(int neighbor : roads[vertex]) {
                    if(elevation[neighbor] >= elevation[vertex]) 
                        good_obs = false ;
                    if(!visited[neighbor]) {
                        obs.push(neighbor) ;
                        visited[neighbor] = true ;
                    }
                }
                if(good_obs)
                    counter++ ;
            }
        }
    }

    cout << counter << endl ;
    
   
    
    
}