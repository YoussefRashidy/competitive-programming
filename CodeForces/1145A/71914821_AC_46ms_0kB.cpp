#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
#include<set>
#include <iomanip>
using namespace std;

int thanos_sort(int p , int q , vector<int> & a) {
    bool sorted = true ;
    
    for(int i = p ; i < q ; i++) {
        if(a[i] > a[i+1]) {
            sorted = false ;
            break;
        }
    }
    if(sorted) {
        return q - p + 1 ;
    }
    int mid = (q + p)/2 ;
    return max(thanos_sort(p,mid,a),thanos_sort(mid+1,q,a)) ;

}
int main() {
    int n ; 
    cin >> n ;
    vector<int> a(n) ;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    cout << thanos_sort(0,n-1,a) << endl ;
}