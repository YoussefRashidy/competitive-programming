#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;
vector<int> primes;
void sieve(int n);
vector<long long> primeFactors(long long n);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    sieve(1e6);
    while (t--)
    {
        long long n;
        cin >> n;
        auto it = upper_bound(primes.begin(), primes.end(), n);
        if (it == primes.end())
        {
            long long number = n;
            int siz = INT_MAX;
            do
            {
                number++;
                vector<long long> facs = primeFactors(number);
                siz = facs.size();
            } while (siz != 1);
            cout << number << '\n' ;
        }
        else
        {
            cout << *it << '\n';
        }
    }
}
vector<long long> primeFactors(long long n)
{
    vector<long long> primeFac;
    for (auto &&i : primes)
    {
        if (1LL * i * i > n)
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