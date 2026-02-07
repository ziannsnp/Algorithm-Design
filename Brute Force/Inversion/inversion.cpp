#include<iostream>
#include<vector>

using namespace std;

long long count_n;

void merge(vector<int> &v, int start, int m, int stop, vector<int> &tmp){
    int bi = start;
    int ci = m+1;

    for (int i=start; i<=stop; i++){
        if(ci > stop) {
            tmp[i] = v[bi++];
            continue;
        }
        if(bi > m) {
            tmp[i] = v[ci++];
            continue;
        }
        // have both
        if (v[bi] > v[ci]){
            count_n += m - bi + 1;
            tmp[i] = v[ci++];
        }
        else { // v[ci] > v[bi]
            tmp[i] = v[bi++];
        }
    }
    for (int i = start; i<= stop; i++){
        v[i] = tmp[i];
    }
}


void merge_sort(vector<int> &v, int start, int stop, vector<int> &tmp){
    if (start < stop){
        int m = (start + stop) / 2 ;
        merge_sort(v, start, m, tmp);
        merge_sort(v, m+1, stop, tmp);
        merge(v, start, m, stop, tmp);
    }
}


int main(){
    int n, e;
    cin >> n;
    count_n = 0;
    vector<int> data(n);
    vector<int> tmp(n);
    for (int i=0; i<n; i++){ //input vector data
        cin >> e;
        data[i] = e;
    }
    merge_sort(data, 0, n-1, tmp);
    cout << count_n;
}