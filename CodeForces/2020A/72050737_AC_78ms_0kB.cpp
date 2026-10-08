#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
#include<set>
#include <iomanip>
#include<queue>
using namespace std;

vector<int> to_base(int n , int base){
    vector<int> num ;
    while(n > 0){
        num.push_back(n % base) ;
        n /= base ;
    }
    reverse(num.begin() , num.end()) ;
    return num ;
}
int main(){
    int t ;
    cin >> t ;
    while(t--){
        int n , k;
        cin >> n >> k ;
        if(k == 1) {
            cout << n << endl ;
            continue;
        }
        auto num = to_base(n,k) ;
        int num_ops = 0 ;
        for(int digit : num ) {
            num_ops += digit ;
        }
        cout << num_ops << endl ;
    }
}