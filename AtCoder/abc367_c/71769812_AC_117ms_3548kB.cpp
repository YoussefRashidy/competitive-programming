#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include <iomanip>
#include <fstream>
#include<queue>
#include<climits>
#include<bitset>
#include<set>

using namespace std ;


void backtrack(int index,vector<int> & a , int k , vector<int> & sequence , int sum ) {
    if(sequence.size() == a.size() && sum % k == 0) {
        for(int num : sequence) {
            cout << num << " " ;
        }
        cout << endl ;
    }

    if(index >= a.size() )
        return ;
    
    for(int i = 1 ; i <= a[index] ; i++) {
        sequence.push_back(i) ;
        sum+= i ;
        backtrack(index+1,a,k,sequence,sum);
        sequence.pop_back();
        sum-=i;
    }
}

int main() {
    int n ,k; 
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> sequence ;
    backtrack(0,a,k,sequence,0) ;
}