#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
  Problem (summary):
  - Print all permutations of 0..n-1 in lexicographic (vector) order.
  - But only keep permutations that satisfy constraints (a, b):
      a must appear BEFORE b.
  - Given guarantee: each b will not repeat across constraints
    => each number b has at most ONE required predecessor a.
*/

int n, m;

// pre[x] = y means: y must appear before x.
// If x has no constraint, pre[x] = -1.
vector<int> pre;

// perm[pos] = the value we placed at position pos in the permutation.
vector<int> perm;

// used[x] = true if number x is already placed in perm.
vector<char> used;

// Buffer output for speed (printing line-by-line with cout can be slower).
string out;

/*
  dfs(pos):
  - We are filling the permutation from left to right.
  - pos is the next position to fill (0..n).
*/
void dfs(int pos) {
    // Base case: if we've placed n numbers, we have a full permutation.
    if (pos == n) {
        // Print the permutation as one line.
        for (int i = 0; i < n; i++) {
            if (i) out.push_back(' ');
            out += to_string(perm[i]);
        }
        out.push_back('\n');
        return;
    }

    /*
      To output permutations in lexicographic (vector) order:
      - At each position, try the smallest available number first.
      - So we loop x from 0 to n-1 in increasing order.
    */
    for (int x = 0; x < n; x++) {
        // Skip if x is already used.
        if (used[x]) continue;

        /*
          Constraint check / pruning:
          If x has a required predecessor need = pre[x],
          then we are NOT allowed to place x until need has already appeared.

          This guarantees that we will never create a prefix that violates
          (need before x). So we prune early and avoid useless recursion.
        */
        int need = pre[x];
        if (need != -1 && !used[need]) continue;

        // Choose x for this position.
        used[x] = 1;
        perm[pos] = x;

        // Recurse to fill the next position.
        dfs(pos + 1);

        // Undo the choice (backtrack) to try the next candidate x.
        used[x] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read input: n (size), m (number of constraints)
    cin >> n >> m;

    // Initialize all to "no predecessor required".
    pre.assign(n, -1);

    /*
      Read constraints (a, b): a must come before b.
      Because "b will not repeat", we can store only one predecessor per b.
    */
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        pre[b] = a;
    }

    // Prepare arrays for recursion.
    perm.assign(n, 0);
    used.assign(n, 0);

    // Start recursion at position 0.
    dfs(0);

    // Print everything at the end.
    cout << out;
    return 0;
}
