#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;

struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

long long max_gems(int current , int prev, int d, int max_jem, vector<int> &jems, vector<bool> &has_jem, vector<vector<long long>> &memo2) ;
int main() {
    int n , d ; 
    cin >> n >> d ;
    vector<int> jems(30001,0) ;
    vector<bool> has_jem(30001,false) ;
    int max_jem = 0 ;
    for(int i = 0 ; i < n ; i++){
        int jem_locations ;
        cin >> jem_locations ;
        jems[jem_locations] ++ ;
        has_jem[jem_locations] = true ;
        max_jem = max(max_jem,jem_locations) ;
    }
    unordered_map<pair<int,int> , int , PairHash> memo ;
    vector<vector<long long>> memo2(30001,vector<long long>(502,-1)) ;
    long long max_gems_collected = max_gems(d,0,d,max_jem,jems,has_jem,memo2)  ;
    cout << max_gems_collected << endl ;
}

long long max_gems(int current , int prev, int d,int max_jem, vector<int> &jems, vector<bool> &has_jem, vector<vector<long long>> &memo2) {
    if(current > max_jem)
        return 0 ;
    if(memo2[current][current-prev - d + 250] != -1)
        return memo2[current][current-prev - d + 250] ;
    int ch1 , ch2 ,ch3 ;
    int l = current - prev ;

    ch1 = (l-1 > 0 && l-1 <= max_jem) ? max_gems(current+l-1, current,d,max_jem,jems,has_jem,memo2) : 0 ;
    ch2 = (l > 0 && l <= max_jem) ? max_gems(current+l, current,d,max_jem,jems,has_jem,memo2) : 0 ;
    ch3 = (l+1 > 0 && l+1 <= max_jem) ? max_gems(current+l+1, current,d,max_jem,jems,has_jem,memo2) : 0 ;

    long long max_gems_collected = max({ch1,ch2,ch3}) + (has_jem[current] ? jems[current] : 0 );
    memo2[current][current-prev - d + 250] = max_gems_collected ;
    return max_gems_collected ;

}