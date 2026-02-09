#include <iostream>
#include <vector>
using namespace std;
void combi_exact(int n,
                 vector<int> &sol,
                 int len,
                 int k, int chosen)
{
    if (len < n)
    {
        if (len - chosen < n - k)
        {
            sol[len] = 0;
            combi_exact(n, sol, len + 1, k, chosen);
        }
        if (chosen < k)
        {
            sol[len] = 1;
            combi_exact(n, sol, len + 1, k, chosen + 1);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
            cout << sol[i];
                
        cout << endl;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> sol(b,0);
    combi_exact(b, sol, 0, a, 0);
}