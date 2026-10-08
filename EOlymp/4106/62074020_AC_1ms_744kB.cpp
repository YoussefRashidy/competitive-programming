#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <numeric>
using namespace std;
void subsets(int start, int end , vector<int> &currentSet);
vector <vector<int>> sets;
vector<int> nums;
string toString(vector<int>&vec)
{
    string r = "" ;
    for (auto &&i : vec)
    {
        r+=i ;
    }
    return r ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        nums.push_back(i+1) ;
    }
    vector<int> sub ;
    subsets(0, n,sub);
    sort(sets.begin(),sets.end(),[]( vector<int> &a,  vector<int> &b) {
        if (a.size() != b.size())
            return a.size() < b.size();
        return toString(a) < toString(b);
    }) ;
    for (auto &&i : sets)
    {
        if (i.empty())
        {
            continue;
        }
        
        for (auto &&k : i)
        {
            cout << k;
        }
        cout << '\n';
    }
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
