#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

vector<long long> dijkstra(vector<vector<pair<long long,int>>> &graph , vector<long long> & prices ) ;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m ;
    cin >> n >> m ;
    vector<vector<pair<long long,int>>> graph(n+1) ;
    for (int i = 0; i < m; i++) {
        int u,v ;
        long long w ;
        cin >> u >> v >> w ;
        graph[u].push_back({2*w,v}) ;
        graph[v].push_back({2*w,u}) ;
    }
    vector<long long> prices(n+1) ;
    for (int i = 1; i < n+1; i++)
    {
        cin >> prices[i] ;
    }
    vector<long long> distance = dijkstra(graph , prices) ;
    for (int i = 1; i < n+1; i++)
    {
        cout << distance[i] << " " ;
    }
    cout << endl ;
    
}

vector<long long> dijkstra(vector<vector<pair<long long,int>>> &graph , vector<long long> & prices ) {
    vector<long long> current_distance(graph.size(),LLONG_MAX) ;
    vector<bool> found_shortest_path(graph.size(),false) ;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq ;
    for(int i = 1; i < graph.size(); i++) {
        pq.push({prices[i],i}) ;
        current_distance[i] = prices[i] ;
    }
    while(!pq.empty()) {
        auto[distance , vetrex] = pq.top() ; pq.pop() ;
        if(found_shortest_path[vetrex])
            continue ;
        found_shortest_path[vetrex] = true ;
        for(auto[weight , neighbor] : graph[vetrex]) {
            if(found_shortest_path[neighbor])
                continue ;
            if(current_distance[neighbor] > weight + current_distance[vetrex]) {
                current_distance[neighbor] = weight + current_distance[vetrex] ;
                pq.push({current_distance[neighbor],neighbor}) ;
            }
        }
    }
    return current_distance ;
}