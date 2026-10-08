#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
#include<set>
using namespace std;
void password(int c , string& pass,vector<vector<char>>& grid1,vector<vector<char>> &grid2 , set<string>& candiadates) {
    if(c>=5) {
        candiadates.emplace(pass) ;
        return ;
    }

    set<char> common ;
    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j <  6 ; j++) {
            if(grid1[i][c] == grid2[j][c]) {
                common.emplace(grid1[i][c]) ;
            }
        }
    }
    for(char ch : common) {
        pass.push_back(ch) ;
        password(c+1,pass,grid1,grid2,candiadates) ;
        pass.pop_back() ;
    }

}
int main(){
    int t ;
    cin >> t ;
    while(t--) {
        int k ;
        cin >> k ;
        vector<vector<char>> grid1(6,vector<char>(5,0)) ;
        vector<vector<char>> grid2(6,vector<char>(5,0)) ;
        for(int i = 0 ; i < 6 ; i++) {
            for(int j = 0 ; j < 5 ; j++) {
                cin >> grid1[i][j] ;
            }
        }
        for(int i = 0 ; i < 6 ; i++) {
            for(int j = 0 ; j < 5 ; j++) {
                cin >> grid2[i][j] ;
            }
        }
        string pass = "" ;
        set<string> candiadates ;
        password(0 , pass , grid1 , grid2 , candiadates) ;
        if(candiadates.size() < k) {
            cout << "NO" << endl ;
        }
        else {
            auto it = candiadates.begin() ;
            for(int i = 0 ; i < k - 1 ; i++) {
                it++ ;
            }
            cout << *it << endl ;   
        }
    }
}