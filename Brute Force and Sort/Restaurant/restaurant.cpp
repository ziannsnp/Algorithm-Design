#include<iostream>
#include<vector>
#include<map>

using namespace std;

long long served_by_time(long long t, 
                        const vector<long long> &T, 
                        long long cap){
    long long s = (long long)T.size();
    for(long long Ti : T) {
        s += t/Ti;
        if(s >= cap) return cap;
    }
    return s;
}

long long time_of_customer(long long c,
                            const vector<long long> &T){
    long long N = (long long)T.size();

    if(c <= N) return 0;

    long long lo = 0, hi = 1;
    //find upper bound hi for *2
    while (served_by_time(hi, T, c) < c){ //s(hi) < c
        hi *= 2;
    }
    //find smallest t that s(t) >= c
    while (lo < hi){
        long long mid = lo + (hi - lo)/2;
        if(served_by_time(mid, T, c) >= c) hi = mid;
        else lo = mid +1;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, A;
    cin >> N >> A;

    vector<long long> T(N);
    for (int i = 0; i < N; i++) cin >> T[i];

    for (int i = 0; i < A; i++) {
        long long c;
        cin >> c;
        cout << time_of_customer(c, T) << "\n";
    }
    return 0;
}