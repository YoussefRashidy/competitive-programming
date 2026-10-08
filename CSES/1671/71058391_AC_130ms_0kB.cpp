#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std ;


vector<long long> dijkstra(int source ,int v ,vector<vector<pair<long long, int>>> &graph) ;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int v , k ;
    cin >> v >> k ;
    vector<vector<pair<long long, int>>> graph(v+1) ;
    for(int i = 0 ; i < k ; i++) {
        int u,v;
        long long w ;
        cin >> u >> v >> w ;
        graph[u].push_back({w,v}) ;
    }
    vector<long long> distances = dijkstra(1 , v , graph) ;
    for(int i = 1 ; i < v+1 ; i++) {
        cout << distances[i] << " " ;     
    }
    
    cout << endl ;

    return 0;

}

vector<long long> dijkstra(int source ,int v ,vector<vector<pair<long long, int>>> &graph) {
    vector<bool> found_shortest_path (v+1,false) ;
    vector<long long> current_distance(v+1,LLONG_MAX) ;
    vector<int> parent(v+1,-1) ;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq ;

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
                parent[neighbor] = vertex ;
            }
        }
    }
    return current_distance ;
}

