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

int main(){
    int t ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        vector<int> a(n) ;
        for(int i = 0 ; i < n ; i++){
            cin >> a[i] ;
        }
        for(int i = 0 ; i < n ; i++){
            int xor_val = 0 ;
            for(int j = 0 ; j < n ; j++){
                if(j != i)
                xor_val ^= a[j] ;
            }
            if(xor_val == a[i]){
                cout << xor_val << endl ;
                break ;
            }
        }
    }
}