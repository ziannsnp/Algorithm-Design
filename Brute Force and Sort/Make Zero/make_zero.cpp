#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define M 16777216

int make_zero(int n, 
              queue<int> &q, 
              vector<int> &dist){
    while(1){
        int V = q.front();
        q.pop();
        if(V==0) return dist[V];
        int s1 = (V + 1) % M;
        int s2 = (V * 2) % M;
        if (dist[s1] == -1) {
            dist[s1] = dist[V] + 1;
            q.push(s1);
        }
        if (dist[s2] == -1) {
            dist[s2] = dist[V] + 1;
            q.push(s2);
        }
    }

}

int main(){
    vector<int> dist(M,-1);
    int n;
    cin >> n;
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    make_zero(n, q, dist);
    cout << dist[0] << "\n";
    return 0;
}