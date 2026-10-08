#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <climits>
#include <map>
using namespace std;
map<int, int> prime(vector<int> &vec) ;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        map<int, int> primes = prime(vec);
        bool valid = true;
        for (auto it = primes.begin(); it != primes.end(); it++)
        {
            if (it->second % n != 0)
            {
                valid = false;
                break;
            }
        }
        cout << (valid ? "YES" : "NO") << '\n';
    }
}

map<int, int> prime(vector<int> &vec)
{
    map<int, int> primes;
    for (auto num : vec)
    {
        while (num % 2 == 0)
        {
            ++primes[2];
            num /= 2;
        }
        for (int i = 3; i * i <= num; i++)
        {
            while (num % i == 0)
            {
                ++primes[i];
                num /= i;
            }
        }
        if (num > 1)
        {
            ++primes[num];
        }
    }
    return primes;
}