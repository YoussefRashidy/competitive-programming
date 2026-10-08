#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m ;
    int a ;
    pair <int,int> p ;
    cin >> n ;
    cin >> m ;
    deque <pair<int,int>> que ;
    for (int i = 0; i < n; i++)
    {
        cin >> a ;
        pair <int,int> pi = {i,a} ;
        que.push_back(pi) ;
    }
    while (!que.empty())
    {
        p = que.front() ;
        p.second -= m ;
        if(p.second <= 0)
        {
            que.pop_front() ;
        }
        else
        {
            que.pop_front() ;
            que.push_back(p) ;
        }
    }
    cout << p.first+1 ;
    
    
    
}    