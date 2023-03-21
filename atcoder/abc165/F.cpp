#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& G, vector<int>& A, int v, int p, vector<int>& lis, vector<int>& save) {
    int sz = lis.size();
    int x = A[v];

    if(sz == 0 || x > lis.back()) {
        lis.push_back(x);

        save[v] = lis.size();

        for(int nei : G[v]) {
            if(nei != p) {
                dfs(G, A, nei, v, lis, save);
            }
        }
        lis.pop_back();
    } else {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        int i = it - lis.begin();
        int pre_x = *it;
        lis[i] = x;

        save[v] = lis.size();
        
        for(int nei : G[v]) {
            if(nei != p) {
                dfs(G, A, nei, v, lis, save);
            }
        }

        lis[i] = pre_x;
    }
}

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    vector<int> save(N, 1);
    vector<int> lis;
    dfs(G, A, 0, -1, lis, save);

    for(int i = 0; i < N; i++) {
        cout << save[i] << '\n'; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
