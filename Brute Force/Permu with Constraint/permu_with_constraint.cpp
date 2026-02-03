#include <iostream>
#include <vector>
#include <map>

using namespace std;

void perm(int n, vector<int> &sol, 
          int len, vector<bool> &used){
    if (len < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (used[i] == false)
            {
                used[i] = true;
                sol[len] = i;
                perm(n, sol, len + 1, used);
                used[i] = false;
            }
        }
    }
    // else
    // {
    //     for (auto &x : sol)
    //         cout << x;
    //     cout << endl;
    // }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, p; // n - length of solution | p - # of pair
    map<int, int> m;
    for (int i = 0; i < p; i++)
    {
        int a, b; // a comes before b
        m[b] = a; // b ไม่ซ้ำกันเลย
    }
    vector<int> sol;
    vector<bool> used(n, false);

    perm(n, sol, 0, used);
    sort(sol.begin(), sol.end());
    for (auto x : sol){
        for (int i = 0; i < n; i++){
            cout << x[i] ;
        }
    }
        
}