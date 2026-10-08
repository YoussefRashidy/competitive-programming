#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

vector<vector<long long>> all_pairs_dijkstra(vector<vector<pair<long long , int>>>& graph, vector<pair<long long, int>> &train_routes,int n) ;
int main() {
    int n , m , k ;
    cin >> n >> m >> k ;
    vector<vector<pair<long long , int>>> graph (n+1) ;
    for (int i = 0; i < m; i++)
    {
        int u , v ;
        long long w ;
        cin >> u >> v >> w ;
        graph[u].push_back({w,v});
        graph[v].push_back({w,u});
    }
    vector<pair<long long , int>> train_routes(k) ;
    for(int i = 0; i < k; i++)
    {
        int v ;
        long long w ;
        cin >> v >> w ;
        train_routes[i] = {w,v} ;
    }

    vector<long long> shortest_path = all_pairs_dijkstra(graph , train_routes , 1 )[1] ;
    vector<int> parent(n+1) ;
    for(int i = 1 ; i <= n ; i++) {
        for(auto[w,v] : graph[i]) {
            if(shortest_path[i]+w == shortest_path[v]) {
                parent[v]++ ;
            }
        }
    }    
    int answer = 0 ;
    vector<bool> reached(n+1,false) ;
    for(auto[w,v] : train_routes) {
        if(shortest_path[v] < w || parent[v] >= 1) {
            answer++ ;
        }
        else if(reached[v]) {
            answer++ ;
        }
        else {
            reached[v] = true ;
        }
    }

    cout << answer << endl ;
    
}

vector<vector<long long>> all_pairs_dijkstra(vector<vector<pair<long long , int>>>& graph, vector<pair<long long, int>> &train_routes ,int n) {
    vector<vector<long long>> shortest_path (n+1,vector<long long>(graph.size() , LONG_LONG_MAX)) ;
    for (int i = 1; i <= n; i++)
    {
        priority_queue<pair<long long, int>, vector<pair<long long , int>> , greater<pair<long long ,int>>> pq ;
        vector<bool> found_shortest_path(graph.size(),false) ;
        pq.push({0,i}) ;

        for(auto[edge_weight,neighbor] : train_routes) {
            pq.push({edge_weight,neighbor}) ;
            shortest_path[i][neighbor] = edge_weight  ;
        }
        while (!pq.empty())
        {
            auto  [weight ,vertex] = pq.top() ; pq.pop() ;
            if(found_shortest_path[vertex])
                continue;
            if(weight == LONG_LONG_MAX)
                continue;
            found_shortest_path[vertex] = true ;
            shortest_path[i][vertex] = weight ;
            for(auto [edge_weight , neighbor] : graph[vertex]) {
                if(found_shortest_path[neighbor])
                    continue;
                if(edge_weight + weight < shortest_path[i][neighbor]) {
                    shortest_path[i][neighbor] = edge_weight + weight ;
                    pq.push({shortest_path[i][neighbor],neighbor}) ;
                }
            }

        }
    }

    return shortest_path ;
    
}
