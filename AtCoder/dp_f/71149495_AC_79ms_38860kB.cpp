#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

int lcs(const string &s, const string &t, int i, int j, vector<vector<int>> &memo, vector<vector<bool>> &visited);
int main() {
    string s, t;
    cin >> s >> t;
    vector<vector<int>> memo(s.size(), vector<int>(t.size(), -1));
    vector<vector<bool>> visited(s.size(), vector<bool>(t.size(), false));
    int length = lcs(s,t,0,0,memo,visited) ;
    int i = 0 , j = 0 ;
    while(i < s.size() && j < t.size()) {
        if(s.at(i) == t.at(j)) {
            cout << s.at(i) ;
            i++ ;
            j++ ;
        }
        else {
            if(i+1 >= s.size() && j+1 < t.size()) {
                j++ ;
            }
            else if(i+1 < s.size() && j+1 >= t.size()) {
                i++ ;
            } 
            else if(i+1 >= s.size() && j+1 >= t.size()) {
                break ;
            }
            else if(memo[i+1][j] > memo[i][j+1]) {
                i++ ;
            }
            else {
                j++ ;
            }
        }
    }
    cout << endl ;
}

int lcs(const string &s, const string &t, int i, int j, vector<vector<int>> &memo, vector<vector<bool>> &visited) {
    if(i >= s.size() || j >= t.size()) {
        return 0 ;
    }

    if(visited[i][j]) {
        return memo[i][j] ;
    }
    visited[i][j] = true ;

    int length ; 
    
    if(s.at(i) == t.at(j)) {
        length = 1 + lcs(s,t,i+1,j+1,memo,visited) ;
    }
    else {
        int sub1 = lcs(s,t,i+1,j,memo,visited) ;
        int sub2 = lcs(s,t,i,j+1,memo,visited) ;
        length = (sub1 > sub2) ? sub1 : sub2 ;
    }

    return memo[i][j] = length ;
}