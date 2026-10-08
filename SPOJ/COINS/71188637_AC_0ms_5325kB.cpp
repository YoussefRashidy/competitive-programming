#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;

long long max_dollars(long long n , unordered_map<long long , long long> &memo) ;
int main() {
    long long n ;
    while(cin >> n) {
        unordered_map<long long , long long> memo ;
        cout << max_dollars(n , memo) << endl ;
    }
}

long long max_dollars(long long n , unordered_map<long long , long long> &memo){
    if(n == 0 ) 
        return 0 ;
    if(memo.find(n) != memo.end())
        return (*memo.find(n)).second ;
    
    long long ch1 = n ;
    long long ch2 = max_dollars(n/2,memo) + max_dollars(n/3,memo) + max_dollars(n/4,memo) ;
    long long max_money = max(ch1 , ch2) ;
    memo.insert({n,max_money}) ;
    return max_money ;
}