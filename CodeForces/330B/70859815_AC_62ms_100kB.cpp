#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n , m ;
    cin >> n >> m ;
    vector<int> forbidden(n+1) ;
    for (size_t i = 0; i < m; i++)
    {
        int u , v ;
        cin >> u >> v ;
        forbidden[u]++ ;
        forbidden[v]++ ;
    }

    int starNode = -1 ;
    for (size_t i = 1; i < n+1; i++)
    {
        if(forbidden[i]== 0) {
            starNode = i ;
            break; 
        }
    }

    cout << n-1 << endl ;
    for (int i = 1; i < n+1; i++)
    {
        if(i != starNode)
            cout << i << " " << starNode << endl ;
    }
    
    
    
}