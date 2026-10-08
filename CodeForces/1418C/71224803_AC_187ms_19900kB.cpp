#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;

int mortal_kombat(int boss , int player ,int n,vector<int>& bosses , vector<vector<int>>& memo ) ;

int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int n;
        cin >> n ;
        vector<int> bosses(n) ;
        for(int i = 0 ; i < n ; i++) {
            cin >> bosses[i] ;
        }
        vector<vector<int>> memo(n,vector<int>(2,-1)) ;
        cout << mortal_kombat(0,0,n,bosses,memo) << endl ;
    }
}

int mortal_kombat(int boss , int player ,int n,vector<int>& bosses , vector<vector<int>>& memo ) {
    if(boss >= n)
        return 0 ;
    if(memo[boss][player] != -1)
        return memo[boss][player] ;

    int skip_points = INT_MAX ;
    switch (player)
    {
    case 0:
        if(bosses[boss] == 0) {
            if(boss+1 < n)
                if(bosses[boss+1] == 0)
                    skip_points = min(mortal_kombat(boss+2,1,n,bosses,memo) , mortal_kombat(boss+1,1,n,bosses,memo));
                else 
                    skip_points = min(1 + mortal_kombat(boss+2,1,n,bosses,memo) , mortal_kombat(boss+1,1,n,bosses,memo));
            else 
                skip_points = 0 ;
        }
        else 
            if(boss+1 < n)
                if(bosses[boss+1] == 0)
                    skip_points = min(1 + mortal_kombat(boss+2,1,n,bosses,memo) , 1+mortal_kombat(boss+1,1,n,bosses,memo));
                else 
                    skip_points = 1 + mortal_kombat(boss+1,1,n,bosses,memo) ;
            else
                skip_points = 1 ;
        break;
    case 1:
        skip_points = min(mortal_kombat(boss+1,0,n,bosses,memo) , mortal_kombat(boss+2,0,n,bosses,memo)) ;
        break ;
    default:
        break;
    }
    return memo[boss][player] = skip_points ;
}