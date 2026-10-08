#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void dfs(int character,int & least_gold , vector<vector<int>> &chars ,vector<int> &gold,vector<bool> &visited) ;
int main() {
    int n , m; 
    cin >> n >> m ;
    vector<vector<int>> chars(n+1) ;
    vector<int> gold(n+1) ;
    for (int i = 1; i <= n; i++)
    {
        cin >> gold[i] ;
    }
    
    for(int i = 0 ; i < m ; i++ ) {
        int u,v;
        cin >> u >> v ;
        chars[u].push_back(v) ;
        chars[v].push_back(u) ;
    }
    vector<bool> visited(n+1,false) ;

    long long cost = 0 ;

    for (int i = 1; i < n+1; i++)
    {
        if (!visited[i])
        {
            int least_gold = INT_MAX ;
            dfs(i,least_gold,chars,gold,visited) ;
            cost+= least_gold ;
        }
        
    }

    cout << cost << endl ;
    

}

void dfs(int character,int & least_gold , vector<vector<int>> &chars ,vector<int> &gold,vector<bool> &visited) {
    visited[character] = true ;
    if(gold[character] < least_gold)
        least_gold = gold[character] ;
    for(int char_friend : chars[character]) {
        if(!visited[char_friend])
            dfs(char_friend,least_gold,chars,gold,visited) ;
    }
}