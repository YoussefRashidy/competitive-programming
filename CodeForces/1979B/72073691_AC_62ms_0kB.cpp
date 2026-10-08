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
        int a , b ;
        cin >> a >> b ;
        for(int i = 0 ; i < 30 ; i++){
            if((a & (1 << i)) != (b & (1 << i))){
                cout << (1 << i) << endl ;
                break ;
            }
        }
    }
}