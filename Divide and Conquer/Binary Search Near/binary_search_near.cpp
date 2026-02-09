#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int bsearch(vector<int> &v, int k, int start, int stop){
    if (start == stop){
        if (start == 0){
            return (v[start] <= k) ? v[start] : -1;
        }
        return (v[start] <= k ) ? v[start] : v[--start];
    } 
    int m = (start + stop) >> 1;
    if (v[m] >= k) return bsearch(v, k, start, m);
    else return bsearch(v, k, m+1, stop);
}

int main(){
    int n , m, ele;
    cin >> n >> m;

    vector<int> data(n);
    for (int i=0; i<n; i++){
        cin >> ele;
        data[i] = ele;
    }

    vector<int> A(m);
    for (int i=0; i<m; i++){
        cin >> ele;
        A[i] = ele;
    }

    for (int i=0; i<m; i++){
        cout << bsearch(data, A[i], 0, data.size()-1) << "\n";
    }
}