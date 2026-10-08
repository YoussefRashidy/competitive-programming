#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include <iomanip>
#include <fstream>

using namespace std ;


int dp(int i ,int j ,string &s1 ,string &s2,int b,vector<vector<vector<int>>> &memo ) ;
int main() {
    string s1 ,s2 ;
    cin >> s1 >> s2 ;
    vector<vector<vector<int>>> memo(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(401,-1))) ;
    int min_len = dp(0,0,s1,s2,0,memo) ;
    int i = 0 , j = 0 , b = 0 ;
    string ans = "" ;
    while(i < s1.size() || j < s2.size()) {
        int ni = i + (i < s1.size() && s1[i] == '(') ;
        int nj = j + (j < s2.size() && s2[j] == '(') ;
        int ch1 = (b < 400) ? dp(ni,nj,s1,s2,b+1,memo) + 1 : INT_MAX ;
        int ch2 ;
        if(b > 0) {
            ni =  i + (i < s1.size() && s1[i] ==')') ;
            nj =  j + (j < s2.size() && s2[j] == ')') ;
            ch2 = dp(ni,nj,s1,s2,b-1,memo) + 1 ;
        }
        else ch2 = INT_MAX ;
        if(ch1 <= ch2) {
            ans += '(' ;
            i = i + (i < s1.size() && s1[i] == '(') ;
            j = j + (j < s2.size() && s2[j] == '(') ;
            b++ ;
        }
        else {
            ans += ')' ;
            i =  i + (i < s1.size() && s1[i] ==')') ;
            j =  j + (j < s2.size() && s2[j] == ')') ;
            b-- ;
        }
    }
    
    while(b > 0) {
        ans += ')' ;
        b-- ;
    }
    cout << ans << endl ;
}

int dp(int i ,int j ,string &s1 ,string &s2,int b,vector<vector<vector<int>>> &memo ) {
    if(i == s1.size() && j == s2.size())
        if(b==0)
            return 0 ;
        else return b ;
    if(memo[i][j][b] != -1)
        return memo[i][j][b] ;
    
    int ni = i + (i < s1.size() && s1[i] == '(') ;
    int nj = j + (j < s2.size() && s2[j] == '(') ;
    int ch1 = (b < 400) ? dp(ni,nj,s1,s2,b+1,memo) + 1 : INT_MAX ;

    int ch2 ;

    if(b > 0) {
        ni =  i + (i < s1.size() && s1[i] ==')') ;
        nj =  j + (j < s2.size() && s2[j] == ')') ;
        ch2 = dp(ni,nj,s1,s2,b-1,memo) + 1 ;
    }
    else ch2 = INT_MAX ;
    
    return memo[i][j][b] = min(ch1,ch2) ;
    
    
}