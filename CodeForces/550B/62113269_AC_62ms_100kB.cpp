#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long ;
vector<int>nums ;
vector<vector<int>>sets ;
ll sum(vector<int> &vec) ;
void subsets(int start, int end, vector<int> &currentSet) ;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l,r,x ;
    cin >> n >> l >> r >> x ;
    for (int i = 0; i < n; i++)
    {
        int number ;
        cin >> number ;
        nums.emplace_back(number) ;
    }
    vector<int> current ;
    subsets(0,n,current) ;
    int numberOfContest = 0 ;
    for (auto &&i : sets)
    {
        if (i.empty())
        {
            continue;
        }
        
        ll sum1 = sum(i) ;
        auto [minElement,maxElement] = minmax_element(i.begin(),i.end()) ;
        if (sum1 >= l && sum1 <= r && *maxElement-*minElement>=x)
        {
            numberOfContest++ ;
        }
    }
    cout << numberOfContest ;
    
    
}
void subsets(int start, int end, vector<int> &currentSet)
{
    if (start == end)
    {
        sets.emplace_back(currentSet);
        return;
    } else if(start > end) return ;
    currentSet.push_back(nums[start]);
    subsets(start + 1, end, currentSet);
    currentSet.pop_back();
    subsets(start + 1, end, currentSet);
}
ll sum(vector<int> &vec)
{
    ll sum = 0;
    for (auto &&i : vec)
    {
        sum += i;
    }
    return sum;
}