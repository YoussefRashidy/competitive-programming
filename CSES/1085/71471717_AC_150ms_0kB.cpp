#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;
bool can_divide(vector<int>& a ,int k , long long mid) {
    int groups = 1 ;
    long long sum = 0 ;
    for (size_t i = 0; i < a.size(); i++)
    {
        if(sum+a[i] > mid) {
            groups++ ;
            sum = a[i] ;
        }
        else 
            sum+=a[i] ;
    }

    return groups <= k ;
    
}
int main() {
    int n , k ;
    cin >> n >> k ;
    vector<int> a(n) ;
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i] ;
    }
    long long low = *max_element(a.begin() , a.end()) ;
    long long high = accumulate(a.begin() , a.end() , 0LL) ;

    while(low < high) {
        long long mid = low + (high-low)/2 ;
        if(can_divide(a,k,mid)) 
            high = mid ;
        else 
            low = mid + 1;
    }
    cout << low << endl ;
}
