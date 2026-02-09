#include <iostream>
#include <map>
#include <vector>
using namespace std;

template <typename T>
void insertion_sort(vector<T> &A, map<int,int> &m){
    for (int pos = A.size() - 2; pos >= 0; pos--){
        T tmp = A[pos];
        size_t i = pos + 1;
        while (i < A.size() && A[i] < tmp){
            A[i - 1] = A[i];
            m[A[i]]++;
            i++;
        }
        A[i - 1] = tmp;
        //m[tmp] = i-1;
        //max(m[tmp], i-1);
    }
}

int main(){
    int num, qstn;
    cin >> num >> qstn;
    vector<int> A(num);
    // map<int, int> ori_pos;
    map<int, int> new_pos;
    int e;

    for(int i=0; i<num; i++){
        cin >> e;
        A[i] = e;
        // ori_pos[e] = i;
    }

    // insertion_sort(A, new_pos);

    for (int i=0; i<qstn; i++){
        cin >> e;
        int k=0;
        for (int j=0;j<num; j++){
            if(A[j]==e) break;
            if(A[j]>e) k++;
        }
        cout << k << "\n";
        // auto it = lower_bound(A.begin(), A.end(), e);
        // int after_sort = it - A.begin();
        // if (after_sort < ori_pos[e]) {
        //     cout << new_pos[e] << "\n";
        // } else {
        //     cout << 0 << "\n";
        // }
    }

}
