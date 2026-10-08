#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std ;
int heights[1000001] = {0} ;


int main() {
    int n ;
    cin >> n ;
    int ballons[n] ;
    int arrow_count = 0 ;
    for (size_t i = 0; i < n; i++) {
        cin >> ballons[i] ;
    }

    for(size_t i = 0; i < n; i++) {
        if(heights[ballons[i]] == 0) {
            heights[ballons[i]]++ ;
            arrow_count++;
        }
        if (ballons[i] == 1) {
            heights[ballons[i]] --;
        } 
        else {
            heights[ballons[i]] -- ;
            heights[ballons[i]-1]++;
        }
    }

    cout << arrow_count ;
}