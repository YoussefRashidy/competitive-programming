#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;

int recursion(int i , int s , int d ,vector<int> & months) {
    if(i >= 12) {
        int l , h ;
        l = 0 ;
        h = 4 ;
        while(h-l == 4) {
            int sum = 0 ;
            for(int j = l ; j <= h ; j++) {
                sum += months[j] ;
            }
            if(sum >=0)
                return -1 ;
            l++ ;
            if(h+1 < 12)
                h++ ;
        }
        int sum = 0 ;
        for(int j = 0 ; j < 12 ; j++) 
            sum += months[j] ;
        return sum ;
    }

    months[i] = s ;
    int ans1 = recursion(i+1 , s , d , months) ;
    months[i] = -d ;
    int ans2 = recursion(i+1 , s , d , months) ;

    return max(ans1 , ans2) ;

}
int main() {
    int s,d ;
    while( cin >> s >> d ) {
        vector<int> months(12) ;
        int ans = recursion(0 , s , d , months) ;
        if(ans < 0)
            cout << "Deficit" << endl ;
        else 
            cout << ans << endl ;
    }
    
}