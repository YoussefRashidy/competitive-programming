#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <set>
#include <queue>
using namespace std;
int beauty(int x, int y);
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
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        int maxBeauty = 0;
        int maxElement = nums[0];
        for (int k = 0; k < n; k++)
        {
            maxBeauty = max(maxBeauty, beauty(maxElement, nums[k]));
            if (nums[k] > maxElement)
            {

                if (nums[k] >= maxElement * 2)
                {
                    for (int i = 0; i < k; i++)
                    {
                        maxBeauty = max(maxBeauty, beauty(nums[k], nums[i]));
                    }
                }
                else
                {
                    maxBeauty = nums[k];
                }
                maxElement = nums[k];
            }

            cout << maxBeauty << ' ';
        }
        cout << '\n';
    }
}

int beauty(int x, int y)
{
    return (x % y) + (y % x);
}