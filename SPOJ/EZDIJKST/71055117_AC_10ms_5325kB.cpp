#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std ;

vector<int> dijkstra(int source ,int v ,vector<vector<pair<int, int>>> &graph) ;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ;
    cin >> t ;
    while(t--) {
        int v , k ;
        cin >> v >> k ;
        vector<vector<pair<int, int>>> graph(v+1) ;
        for(int i = 0 ; i < k ; i++) {
            int u,v,w ;
            cin >> u >> v >> w ;
            graph[u].push_back({w,v}) ;
        }
        int source , distination ;
        cin >> source >> distination ;
        vector<int> distance = dijkstra(source , v , graph) ;
        if(distance[distination] == INT_MAX) {
            cout << "NO" << endl ;
        } else
            cout << distance[distination] << endl ;
    }

    return 0;

}

vector<int> dijkstra(int source ,int v ,vector<vector<pair<int, int>>> &graph) {
    vector<bool> found_shortest_path (v+1,false) ;
    vector<int> current_distance(v+1,INT_MAX) ;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;

    pq.push({0,source}) ;
    current_distance[source] = 0 ;
    while (!pq.empty())
    {
        auto [distance,vertex] = pq.top() ; pq.pop() ;
        if (found_shortest_path[vertex])
            continue; 
        found_shortest_path[vertex] = true ;
        for(auto[weight , neighbor] : graph[vertex]) {
            if(found_shortest_path[neighbor])
                continue;
            if(current_distance[neighbor] > weight + current_distance[vertex]){
                pq.push({weight+current_distance[vertex],neighbor}) ;
                current_distance[neighbor] = weight + current_distance[vertex] ;
            }
        }
    }
    return current_distance ;
}