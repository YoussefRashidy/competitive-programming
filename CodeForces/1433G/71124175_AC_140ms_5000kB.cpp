#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

vector<vector<long long>> all_pairs_dijkstra(vector<vector<pair<long long , int>>>& graph, int n) ;
int main() {
    int n , m , k  ;
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
    vector<pair<int,int>> queries(k) ;
    for (int i = 0; i < k; i++)
    {
        int a ,b ;
        cin >> a >> b ;
        queries[i] = {a,b} ;
    }

    vector<vector<long long>> shortest_path = all_pairs_dijkstra(graph , n ) ;
    long long answer = LONG_LONG_MAX ;
    for(int u = 1 ; u <= n ; u++) {
        for(auto [w,v] : graph[u]) {
            long long sum = 0 ;
            for(int i = 0 ; i < k ; i ++) {
                auto[a,b] = queries[i] ;
                sum += min(min(shortest_path[a][b], shortest_path[a][u]+shortest_path[v][b]) , shortest_path[a][v] + shortest_path[u][b]) ;
            }
            answer = min(answer, sum) ;
        }
    }
    cout << answer << endl ;

}


vector<vector<long long>> all_pairs_dijkstra(vector<vector<pair<long long , int>>>& graph, int n) {
    vector<vector<long long>> shortest_path (n+1,vector<long long>(n+1 , LONG_LONG_MAX)) ;
    for (int i = 1; i <= n; i++)
    {
        priority_queue<pair<long long, int>, vector<pair<long long , int>> , greater<pair<long long ,int>>> pq ;
        pq.push({0,i}) ;
        vector<bool> found_shortest_path(n+1,false) ;
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
