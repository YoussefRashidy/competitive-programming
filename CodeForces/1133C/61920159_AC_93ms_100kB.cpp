#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    int skills [n] ;
    for (int i = 0; i < n; i++)
    {
        cin >> skills[i] ;
    } 
    int noOfStudents = 0 ;
    int maxTeam = 0 ;
    sort(skills,skills+n);
    int left = 0 ;
    int right = 0 ;
    while (right < n)
    {
        if (skills[right]-skills[left]<=5)
        {
            right++;
            noOfStudents++;
            maxTeam = max(maxTeam,noOfStudents) ;
        }
        else
        {
            left++ ;
            noOfStudents--;
        }
        
    }
    cout << maxTeam ;
    

    
    
    
}