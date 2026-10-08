#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std ;


vector<int> dijkstra(int source ,int v ,vector<vector<pair<long long, int>>> &graph) ;
void print_path(int vertex , vector<int> & parent) ;
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
        graph[v].push_back({w,u}) ;
    }
    vector<int> parent = dijkstra(1 , v , graph) ;
    int current_parent = parent[v] ;
    if(current_parent == -1) {
        cout << -1 << endl ;
    } else {
        print_path(v , parent) ;
    }
    cout << endl ;

    return 0;

}

vector<int> dijkstra(int source ,int v ,vector<vector<pair<long long, int>>> &graph) {
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
    return parent ;
}

void print_path(int vertex , vector<int> & parent) {
    if(vertex == -1) {
        return;
    }
    print_path(parent[vertex] , parent) ;
    cout << vertex << " " ;
}