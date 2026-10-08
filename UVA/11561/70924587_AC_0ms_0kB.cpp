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


bool inBounds(int i, int j , int h , int w) ;
bool adjacentToTrap(int i ,int j , vector<vector<char>> & grid) ;
int dfs(int i , int j , int gold ,vector<vector<char>>& grid , vector<vector<bool>>& visited ) ;
int main() {
    int h , w ;
    while(cin >> w >> h) {
        vector<vector<char>> grid(h,vector<char>(w)) ;
        int px,py ;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                char input ;
                cin >> input ;
                if(input == 'P') {
                    px = i ;
                    py = j ;
                }
                grid[i][j] = input ;
            }
            
        }
        vector<vector<bool>> visited(h,vector<bool>(w,false)) ;
        int max_gold = dfs(px,py,0,grid,visited) ;
        cout << max_gold << endl ;
    }
}

int dfs(int i , int j , int gold ,vector<vector<char>>& grid , vector<vector<bool>>& visited ) {
    visited[i][j] = true ;
    if(grid[i][j] == 'G') {
        gold++ ;
    }

    if(adjacentToTrap(i,j,grid)) 
        return gold ;
    for(auto direction : directions) {
        auto[ti , tj] = direction ;
        ti+= i ; 
        tj+= j ;
        if(inBounds(ti,tj,grid.size(),grid[0].size()) && !visited[ti][tj] && grid[ti][tj] != '#')
            gold = dfs(ti,tj,gold,grid,visited) ;
    }

    return gold ;

}

bool inBounds(int i, int j , int h , int w) {
    return i>=0 && i<h && j>=0 && j<w ;
}

bool adjacentToTrap(int i ,int j , vector<vector<char>> & grid) {
    for(auto direction : directions) {
        auto[ti , tj] = direction ;
        ti+= i ; 
        tj+= j ;
        if(inBounds(ti,tj,grid.size(),grid[0].size()) && grid[ti][tj] == 'T')
            return true ;
    }
    return false ;
}