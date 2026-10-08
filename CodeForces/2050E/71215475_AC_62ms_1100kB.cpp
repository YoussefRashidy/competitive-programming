#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;

int three_strings(int i , int j , string &a , string &b , string &c , vector<vector<int>>& memo) ;
int main() {
    int t ;
    cin >> t;
    while(t--) {
        string a,b,c ;
        cin >> a >> b >> c ;
        vector<vector<int>> memo(a.size()+1 , vector<int>(b.size()+1,-1)) ;
        cout << three_strings(0,0,a,b,c,memo) << endl ;
    }
}

int three_strings(int i , int j , string &a , string &b , string &c , vector<vector<int>>& memo) {
    if(i >= a.size()) {
        int changes = 0 ;
        for(int k = j ; k < b.size() ; k++) 
            if(b.at(k) != c.at(i+k))
                changes ++ ;
        return changes ;
    }

    if(j >= b.size()) {
        int changes = 0 ;
        for(int k = i ; k < a.size() ; k++) 
            if(a.at(k) != c.at(k+j))
                changes ++ ;
        return changes ;
    }
    
    if(memo[i][j] != -1)
        return memo[i][j] ;

    int ch1 , ch2 ;

    if(a.at(i) != c.at(i+j))
        ch1 = 1 + three_strings(i+1,j,a,b,c,memo) ;
    else 
        ch1 = three_strings(i+1,j,a,b,c,memo) ;

    if(b.at(j) != c.at(i+j))
        ch2 = 1 + three_strings(i,j+1,a,b,c,memo) ;
    else 
        ch2 = three_strings(i,j+1,a,b,c,memo) ;

    memo[i][j] = min(ch1, ch2) ;
    return memo[i][j] ;

}