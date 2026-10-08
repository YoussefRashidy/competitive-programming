#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string word ;
    cin >> word ;
    sort(word.begin(),word.end()) ;
    int counter = 0 ;
    vector<string> words ;
    do
    {
        counter++;
        words.push_back(word);
        
    } while (next_permutation(word.begin(),word.end()));
    cout << counter << '\n' ;
    for (auto &&i : words)
    {
        cout << i << '\n' ;
    }
    
    
}