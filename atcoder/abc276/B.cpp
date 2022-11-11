#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> G(N + 1);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;

        G[U].push_back(V);
        G[V].push_back(U);
    } 

    for(int i = 1; i <= N; i++) {
        vector<int>& v = G[i];
        sort(v.begin(), v.end());

        int n = v.size();
        cout << n << " \n"[n == 0];
        for(int j = 0; j < n; j++) {
            cout << v[j] << " \n"[j == n - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
