#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<unordered_map>
using namespace std;

const long long NEINF = -1e18 ;
struct Project {
    int start;
    int end;
    long long profit;
};
long long projects(int i ,int n ,vector<Project>& project , vector<int>& start, vector<long long> & memo) ;
int main() {
    int n ;
    cin >> n ;
    vector<Project> project(n) ;
    vector<int> start(n) ;
    for(int i = 0 ; i < n ; i++) {
        cin >> project[i].start >> project[i].end >> project[i].profit ;
    }
    sort(project.begin(), project.end(),[](Project& a, Project& b) {
        return a.start < b.start ;
    });
    for(int i = 0 ; i < n ; i++) {
        start[i] = project[i].start ;
    }
    vector<long long> memo(n+1,-1) ;
    cout << projects(0,n,project,start,memo) << endl ;
}

long long projects(int i ,int n ,vector<Project>& project , vector<int>& start, vector<long long> & memo) {
    if( i >= n )
        return 0 ;

    if(memo[i] != -1)
        return memo[i] ;
    long long ch1 , ch2 ;
    int next = upper_bound(start.begin() , start.end() , project[i].end) - start.begin();
    ch1 = project[i].profit + projects(next , n , project,start,memo) ;

    ch2 = projects(i+1,n,project,start,memo) ;
    return memo[i]=max(ch1,ch2) ;


}

