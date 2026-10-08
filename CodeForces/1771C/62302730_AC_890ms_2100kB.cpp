#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
using namespace std;
vector<int> primes;
void sieve(int n);
vector<int> primeFactors(int n);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(1e5);
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> numbers(n);
        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }
        map<int, int> countMap;
        bool done = false;
        for (int i = 0; i < n; i++)
        {
            vector<int> facto = primeFactors(numbers[i]);
            for (auto &&k : facto)
            {
                if (++countMap[k] > 1)
                {
                    cout << "YES" << '\n';
                    done = true;
                    break;
                }
            }
            if (done)
            {
                break;
            }
        }
        if (!done)
            cout << "NO" << '\n';
    }
}
vector<int> primeFactors(int n)
{
    vector<int> primeFac;
    for (auto &&i : primes)
    {
        if (i * i > n)
        {
            break;
        }
        if (n % i == 0)
        {
            primeFac.emplace_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        primeFac.push_back(n);
    return primeFac;
}
void sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            for (long long j = 1LL * i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            primes.push_back(i);
}