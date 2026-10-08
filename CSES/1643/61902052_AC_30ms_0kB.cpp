#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    long long max_sum = array[0];
    long long sum = array[0];
    for (int i = 1; i < n; i++)
    {
        sum = max(array[i],sum+array[i]) ;
        max_sum = max(max_sum,sum) ;
    }

    cout << max_sum;
}