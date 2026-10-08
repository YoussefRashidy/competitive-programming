#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int uniquePrimes(int n);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (uniquePrimes(i) == 2)
        {
            count++;
        }
    }
    cout << count ;
}
int uniquePrimes(int n)
{
    vector<int> primes;
    if (n % 2 == 0)
    {
        primes.push_back(2);
    }

    while (n % 2 == 0)
    {
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            primes.push_back(2);
        }

        while (n % i == 0)
        {
            n /= i;
        }
    }
    if (n > 1)
    {
        primes.push_back(n);
    }
    return primes.size();
}