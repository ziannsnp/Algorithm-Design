#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<long long, long long> seg; // key l -> value r

    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;              // new painted interval [a, b]

        long long L = a, R = b;     // we'll expand (merge) into [L, R]

            // 1) Find the first existing segment whose start >= L
        auto it = seg.lower_bound(L);

            // 2) But the segment immediately BEFORE 'it' might still overlap/touch [L,R]
        if (it != seg.begin()) {
            auto pit = prev(it);
                // If previous segment ends at or beyond L-1, it overlaps/touches.
            if (pit->second + 1 >= L) {
                it = pit; // start merging from the previous one
            }
        }

            // 3) Merge all segments that overlap/touch [L,R]
            // Each time we merge, we expand [L,R] and erase the old segment.
        while (it != seg.end() && it->first <= R + 1) {
            L = min(L, it->first);
            R = max(R, it->second);
            it = seg.erase(it);     // erase returns iterator to the next element
        }

        seg[L] = R;
    }
        // output
    bool firstOut = true;
    for (auto &p : seg) {
        if (!firstOut) cout << ' ';
        firstOut = false;
        cout << p.first << ' ' << p.second;
    }
    cout << "\n";

    return 0;
}
