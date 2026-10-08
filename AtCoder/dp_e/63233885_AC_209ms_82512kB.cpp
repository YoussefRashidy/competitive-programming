#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
long long memo[101][100001];
long long minWeight(int n, int array[][2], int i, int value);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int maxWeight;
    cin >> maxWeight;
    int array[n][2];
    memset(memo, -1, sizeof(memo));
    long long maxVal = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> array[i][j];
        }
        maxVal += array[i][1];
    }
    long long val = 0;
    for (int v = maxVal; v >= 0; v--)
    {
        if (minWeight(n, array, 0, v) <= maxWeight)
        {
            cout << v << '\n';
            return 0;
        }
    }
}
long long minWeight(int n, int array[][2], int i, int value)
{
    if (value == 0)
    {
        return 0;
    }
    if (i >= n)
    {
        return LLONG_MAX;
    }
    long long &ref = memo[i][value];
    if (ref != -1)
        return ref;
    long long result = LLONG_MAX;
    if (value >= array[i][1])
    {
        long long taken = minWeight(n, array, i + 1, value - array[i][1]);
        if (taken != LLONG_MAX)
        {
            result = min(result, taken + array[i][0]);
        }
    }
    long long result2 = minWeight(n, array, i + 1, value);
    ref = min(result, result2);
    return ref;
}