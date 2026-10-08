#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int cities[n];
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> cities[i];
    }
    int towers[m];
    for (int i = 0; i < m; i++)
    {
        cin >> towers[i];
    }
    for (int i = 0; i < n; i++)
    {
        int lower = lower_bound(towers, towers + m, cities[i]) - towers ;
        int upper =  upper_bound(towers, towers + m, cities[i]) - towers;
        if (lower != m && towers[lower] == cities[i])
        {
            continue;
        }
        
        int op = lower - 1;
        int op0 = upper ;
        // cout << op<<" "<<op0<<" " ;
        if (op == -1)
            op++;
        if (op0 == m)
            op0--;
        int current = (abs(towers[op] - cities[i]) < abs(towers[op0] - cities[i])) ? abs(towers[op] - cities[i]) : abs(towers[op0] - cities[i]);
        if (current > min)
        {
            min = current;
        }
        // cout << op<<" "<<op0<<" "<<current <<'\n' ;
    }
    cout << min;
}