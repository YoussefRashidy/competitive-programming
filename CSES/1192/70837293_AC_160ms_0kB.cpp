#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>> direcrions = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
} ;

void dfs(int i , int j ,vector<vector<char>> & grid ,vector<vector<bool>> &visited ) ;

int main() {
    int n , m ;
    cin >> n >> m ;
    vector<vector<char>> grid(n,vector<char>(m))  ;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> grid[i][j] ;
        }
    }

    vector<vector<bool>> visited(n,vector<bool>(m,false)) ;
    int room_count = 0 ;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (grid[i][j] != '#' && !visited[i][j])
            {
                room_count++ ;
                dfs(i,j,grid,visited) ;
            }
            
        }
        
    }

    cout<< room_count << endl ;
    
    
}

void dfs(int i , int j ,vector<vector<char>> & grid ,vector<vector<bool>> &visited ) {
    visited[i][j] = true ;
    
    for(pair<int,int> direction : direcrions) {
        int ni = i + direction.first;
        int nj = j + direction.second;
        if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size()) {
            if(grid[ni][nj] != '#' && !visited[ni][nj] ) {
                dfs(ni , nj,grid,visited) ;
            }
        }
    }
}

