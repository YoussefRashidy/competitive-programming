#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> degrees ;
    int n , m ;
    cin >> n >> m ;
    degrees.resize(n+1) ;
    for (size_t i = 0; i < m; i++){
        int u ,v;
        cin >> u >> v ;
        degrees[u]++;
        degrees[v]++ ;
    }
    int degree_one_count = 0 ;
    int degree_two_count = 0 ;
    int tree_degree_count = 0 ;
    for (size_t i = 1; i <= n; i++){
        if (degrees[i] == 1)
            degree_one_count++;
        else if (degrees[i] == 2)
            degree_two_count++;
        else if (degrees[i] == n-1)
            tree_degree_count++ ;
    }


    if (degree_one_count == 2 && degree_two_count == n-2)
        cout << "bus topology" << endl ;
    else if (degree_two_count == n)
        cout << "ring topology" << endl ;
    else if (degree_one_count == n-1 && tree_degree_count == 1)
        cout << "star topology" << endl ;
    else 
        cout << "unknown topology" << endl ;

}