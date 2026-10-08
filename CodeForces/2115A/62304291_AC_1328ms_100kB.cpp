#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <set>
#include <queue>
using namespace std;
int commGCD(vector<int> &numbers);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int minSteps = INT_MAX;
        int n;
        cin >> n;
        vector<int> numbers(n);
        vector<int> copy(n);
        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
            copy[i] = numbers[i];
        }
        if (n == 1)
        {
            cout << 0 << '\n';
            continue;
        }

        int commonGCD = commGCD(numbers);
        bool isPresent = false;
        int countOfGCD = 0;
        for (int i = 0; i < n; i++)
        {
            if (numbers[i] == commonGCD)
            {
                isPresent = true;
                countOfGCD++;
            }
        }
        if (isPresent)
        {
            cout << numbers.size() - countOfGCD << '\n';
            continue;
        }
        // sort(numbers.begin(),numbers.end(),greater<int>()) ;

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i; j < n; j++)
        //     {
        //         int currentGCD = 0;
        //         int steps = 0;
        //         for (int k = i; k <= j; k++)
        //         {
        //             currentGCD = gcd(currentGCD, numbers[k]);
        //             steps++;
        //             if (currentGCD == commonGCD)
        //             {
        //                 minSteps = min(minSteps, steps);
        //                 break;
        //             }
        //         }
        //     }
        // }
        set<int> elements;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            q.push({numbers[i], 0});
            elements.insert(numbers[i]);
        }
        while (!q.empty())
        {
            pair<int, int> pr = q.front();
            q.pop();
            int value = pr.first;
            int steps = pr.second;
            if (value == commonGCD)
            {
                minSteps = steps;
                break;
            }
            for (int i = 0; i < n; i++)
            {
                int newElement = gcd(value, numbers[i]);
                if (!elements.count(newElement))
                {
                    elements.emplace(newElement);
                    q.push({newElement, steps + 1});
                }
            }
        }

        cout << numbers.size() - countOfGCD + minSteps - 1 << '\n';

        // do
        // {
        //     int steps = 0;
        //     int num = copy[0];
        //     for (int i = 1; i < n; i++)
        //     {
        //         num = gcd(num, copy[i]);
        //         steps++;
        //         if (num == commonGCD)
        //         {
        //             break;
        //         }
        //     }
        //     minSteps = min(minSteps, steps);
        //     if (minSteps == 1)
        //     {
        //         break;
        //     }

        // } while (next_permutation(copy.begin(), copy.end()));
    }
}

int commGCD(vector<int> &numbers)
{
    int result = numbers[0];
    for (int i = 1; i < numbers.size(); i++)
    {
        result = gcd(result, numbers[i]);
    }
    return result;
}