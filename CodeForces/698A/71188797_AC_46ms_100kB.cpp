#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;

int min_vactaions(int day , int last_activity ,int n ,vector<int> & days , vector<vector<int>>& memo ) ;
int main() {
    int n ;
    cin >> n ;
    vector<int> days(n) ;
    for(int i = 0 ; i < n ; i++) {
        cin >> days[i] ;
    }
    vector<vector<int>> memo(n , vector<int>(4,-1)) ;

    int min_days = min_vactaions(0,0,n,days,memo) ;
    cout << min_days << endl ;
}

int min_vactaions(int day , int last_activity ,int n ,vector<int> & days , vector<vector<int>>& memo ) {
    if(day >= n)
        return 0 ;
    
    if(memo[day][last_activity] != -1)
        return memo[day][last_activity] ;
    
    int ch1 = INT_MAX;
    int ch2 = INT_MAX,ch3 = INT_MAX,ch4 = INT_MAX ;
    switch (days[day])
    {
        case 0:
            ch1 = 1 + min_vactaions(day+1,0,n,days,memo) ;
            break;
        case 1 :
            if(last_activity != 1)
                ch1 = min( 1 +  min_vactaions(day+1,0,n,days,memo),min_vactaions(day+1,1,n,days,memo)) ;
            else 
                ch1 = 1 +  min_vactaions(day+1,0,n,days,memo) ;
            break;
        case 2 :
            if(last_activity != 2)
                ch1 = min(1 + min_vactaions(day+1,0,n,days,memo),min_vactaions(day+1,2,n,days,memo)) ;
            else 
                ch1 = 1 + min_vactaions(day+1,0,n,days,memo) ;
            break;
        case 3 :
            if(last_activity != 1)
                ch2 = min_vactaions(day+1, 1 ,n ,days , memo) ;
            if(last_activity != 2)
                ch3 = min_vactaions(day+1, 2 ,n ,days , memo) ;
            ch4 = 1 + min_vactaions(day+1,0,n,days, memo) ;
            ch1 = min(min(ch2,ch3),ch4) ;
            break;
        default:
            break;
    }
    return memo[day][last_activity] = ch1 ;

}