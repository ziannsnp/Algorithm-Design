#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int N, Q, in, in_amount;
    cin >> N >> Q;
    map<long long, long long> m;
    vector<long long> data(N);
    
    for (int i=0;  i<N; i++){
        cin >> in >> in_amount;
        m[in] += in_amount;
    }
    vector<long long> prefix(m.size());
    int i=0;
    long long sum=0;
    for( auto p : m ){
        sum += p.second;
        prefix[i] = sum;
        data[i] = p.first;
        i++;
    }

    for (int k=0; k<Q; k++){
        cin >> in;
        auto it = lower_bound(prefix.begin(), prefix.end(), in);
        auto pos = it - prefix.begin();
        cout << data[pos] << "\n";
    }
}