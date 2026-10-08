#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;

long long max_score(int i ,int max,vector<int> &frequency,vector<long long> & memo )  ;
int main() {
    int n ;
    cin >> n ;
    vector<int> sequence(n , 0) ;
    vector<int> frequency(1e5+1 , 0) ;
    int max = 0 ;
    for(int i = 0 ; i < n ; i++) {
        int num ;
        cin >> num ;
        sequence[i] = num ;
        frequency[num] ++ ;
        max = std::max(max,num) ;
    }
    vector<long long> memo(1e5+1 , -1) ;
    cout << max_score(0,max,frequency,memo) << endl ;
}

long long max_score(int i  ,int max,vector<int> &frequency,vector<long long> & memo ) {
    if( i > max)
        return 0 ;
    if(memo[i] != -1)
        return memo[i] ;

    long long ch1 = LLONG_MIN , ch2 = LLONG_MIN ;
    if(frequency[i] > 0)
        ch1 = 1LL*i * frequency[i] + max_score(i+2,max,frequency,memo) ;
    else 
        ch1 = max_score(i+1,max,frequency,memo) ;
    
    ch2 = max_score(i+1,max,frequency,memo) ;
    return memo[i] = std::max(ch1, ch2) ;
}