#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;
vector<pair<int,int>> directions = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
} ;



bool inBounds(int i , int j , vector<vector<char>>& g ) ;
void dfs(int i , int j , int &free_cells ,vector<vector<char>>& g , vector<vector<bool>>& visited) ;
int main() {
    int n , m , k ;
    cin >> n >> m >> k ;
    vector<vector<char>> a(n,vector<char>(m)) ;
    int free_cells = 0 ;
    int start_i , start_j ;
    start_i = start_j = -1 ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j] ;
            if(a[i][j] == '.') {
                free_cells++ ;
                if(start_i == -1) {
                    start_i = i ;
                    start_j = j ;
                }
            }
            
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(m)) ;
    int cells_to_keep = free_cells - k ;
    dfs(start_i , start_j , cells_to_keep , a , visited) ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(a[i][j] == '.' && !visited[i][j]) {
                a[i][j] = 'X' ;
            }
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] ;
        }
        cout << endl ;
    }
}

void dfs(int i , int j , int &free_cells ,vector<vector<char>>& g , vector<vector<bool>>& visited) {
    visited[i][j] = true ;
    free_cells--;
    if(free_cells == 0)
        return ;
    for(auto[di,dj] : directions) {
        int ni = di + i ;
        int nj = dj + j ;
        if(inBounds(ni,nj,g) && !visited[ni][nj] && g[ni][nj] != '#'  && free_cells > 0)
            dfs(ni , nj ,free_cells , g , visited ) ;
    }

}

bool inBounds(int i , int j , vector<vector<char>>& g ) {
    return i >= 0 && i < g.size() && j >=0 && j < g[0].size() ;
}