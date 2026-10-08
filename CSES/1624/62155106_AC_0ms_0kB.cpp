#include <iostream>
#include <vector>
using namespace std;
bool blocked[8][8];
int no_of_sol = 0;
vector<bool> column_taken(8);
vector<bool> diagonal_taken1(15);
vector<bool> diagonal_taken2(15);
void queens(int r) ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 8; i++)
    {
        string row ;
        cin >> row ;
        for (int j = 0; j < 8; j++)
        {
           blocked[i][j] = (row[j]=='*') ? true : false ;
        }
    }
    queens(0) ;
    cout << no_of_sol ;
    

}

void queens(int r) 
{
    if (r == 8)
    {
        no_of_sol++ ;
        return ;
    }
    for (int i = 0; i < 8; i++)
    {
        bool col = !column_taken[i] ;
        bool diag = !diagonal_taken1[r+i] && !diagonal_taken2[r-i+7] ;
        if (!blocked[r][i]&&col && diag)
        {
            column_taken[i] = true ;
            diagonal_taken1[r+i] = true ;
            diagonal_taken2[r-i+7] = true ;
            queens(r+1) ;
            column_taken[i] = false ;
            diagonal_taken1[r+i] = false ;
            diagonal_taken2[r-i+7] = false ;
        }
    }
    
    
    
    
}