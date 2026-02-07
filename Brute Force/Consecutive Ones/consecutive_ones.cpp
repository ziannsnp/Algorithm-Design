#include <iostream>
#include<vector>
#include<string>
using namespace std;

int n, k;
string s;

// dfs(pos, run, ok)
// pos : current index we are filling [0..n]
// run : number of consecutive '1' at the end of current prefix
// ok  : have we ever had a streak of length >= k somewhere in the prefix?
void dfs(int pos, int run, bool ok) {
    if (pos == n) {
        if (ok) cout << s << '\n';
        return;
    }
    
    // Choice 1: put '0' at this position
    s[pos] = '0';   // Putting '0' breaks any consecutive-1 streak => run resets to 0
    dfs(pos + 1, 0, ok);

    // Choice 2: put '1' at this position
    s[pos] = '1';
    int newRun = run + 1;   // Putting '1' extends the consecutive-1 streak => run + 1
    bool newOk = ok || (newRun >= k);
    dfs(pos + 1, newRun, newOk);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    // Prepare an n-length string that we'll fill in-place.
    s.assign(n, '0');

    // Special case: "at least 0 consecutive 1s" => every n-bit string is valid.
    // So we can just start with ok=true.
    bool startOk = (k == 0);

    dfs(0, 0, startOk);

    return 0;
}
