#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;


vector<vector<long long>> dijkstra(int source ,int v ,int k,vector<vector<pair<long long, int>>> &graph ) ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , m , k ;
    cin >> n >> m >> k ;
    vector<vector<pair<long long,int>>> graph(n+1) ;
    for(int i = 0 ; i < m ; i++) {
        int u,v ;
        long long w ;
        cin >> u >> v >> w ;
        graph[u].push_back({w,v}) ;
    }

    vector<vector<long long>> distances = dijkstra(1 , n ,k ,graph ) ;
    for(long long distance : distances[n]) {
        cout << distance << " " ;
    }
    cout << endl ;
        
    

}


vector<vector<long long>> dijkstra(int source ,int v ,int k,vector<vector<pair<long long, int>>> &graph ) {
    vector<int> processed(v+1,0) ;
    vector<vector<long long>> current_distance(v+1) ;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq ;

    pq.push({0,source}) ;
    while (!pq.empty())
    {
        auto [distance,vertex] = pq.top() ; pq.pop() ;
        if (processed[vertex] == k)
        continue; 

        current_distance[vertex].push_back(distance) ;
        processed[vertex] ++ ;
        for(auto[weight , neighbor] : graph[vertex]) {
            if(processed[neighbor] == k)
                continue;
            pq.push({distance + weight, neighbor} ) ;
            
        }
    }
    return current_distance ;
}