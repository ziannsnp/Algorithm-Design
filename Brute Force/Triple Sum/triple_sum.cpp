#include<iostream>
#include<vector>
using namespace std;

bool is_exist(int target, vector<int> &A, int n){
    for (int i=0; i<n-2; i++){ // fix first A
        int first = A[i];
        int l = i+1;
        int r = n-1;
        int target_s = target - first;
        int sum;

        while (l < r){
            sum = A[l] + A[r];
            if( target_s == sum ) return true;

            if( sum > target_s ){
                --r;
            }
            else if (sum < target_s){
                ++l;
            }
        }
    }
    return false;
}

int main(){
    int n,m, in;
    cin >> n >> m;
    vector<int> A(n);
    for (int i=0; i<n; i++){
        cin >> in;
        A[i] = in;
    }

    for (int e=0; e<m; e++){
        cin >> in;
        // B[i] = in;
        if(is_exist(in, A, n)) cout << "YES" << "\n";
        else cout <<"NO"<<"\n";
    }
}