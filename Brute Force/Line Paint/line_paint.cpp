#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // seg stores the already-painted segments as:
    //   key   = left endpoint (L)
    //   value = right endpoint (R)
    //
    // Invariant we maintain after every update:
    //   - segments are sorted by L (map does this automatically)
    //   - segments do NOT overlap and do NOT even touch
    //     (i.e., for consecutive segments [L1,R1], [L2,R2], we have R1 + 1 < L2)
    //
    // Why "do not touch"?
    // Because if R1 + 1 == L2, then the painted region is continuous,
    // and the minimum-number-of-interval representation should merge them.
    map<long long, long long> seg;

    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;              // new painted interval [a, b]

        long long L = a, R = b;     // we'll expand (merge) into [L, R]

        // 1) Find the first existing segment whose start >= L
        auto it = seg.lower_bound(L);

        // 2) But the segment immediately BEFORE 'it' might still overlap/touch [L,R]
        //    Example: existing [2, 9], new [10, 12] -> they "touch" (9+1=10) and should merge.
        if (it != seg.begin()) {
            auto pit = prev(it);
            // If previous segment ends at or beyond L-1, it overlaps/touches.
            if (pit->second + 1 >= L) {
                it = pit; // start merging from the previous one
            }
        }

        // 3) Merge all segments that overlap/touch [L,R]
        //
        // Condition for overlap/touch when segments are sorted:
        //   current segment is [it->first, it->second]
        //   if it->first <= R + 1, then it overlaps or touches our current merged interval [L,R]
        //
        // Each time we merge, we expand [L,R] and erase the old segment.
        while (it != seg.end() && it->first <= R + 1) {
            L = min(L, it->first);
            R = max(R, it->second);
            it = seg.erase(it); // erase returns iterator to the next element
        }

        // 4) Insert the merged interval back into the map.
        //    This preserves the invariant: segments remain disjoint and non-touching.
        seg[L] = R;
    }

    // Output format:
    // Print all remaining segments as:
    //   L1 R1 L2 R2 ... Lk Rk
    // on one line separated by spaces.
    bool firstOut = true;
    for (auto &p : seg) {
        if (!firstOut) cout << ' ';
        firstOut = false;
        cout << p.first << ' ' << p.second;
    }
    cout << "\n";

    return 0;
}
