#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& G, vector<int>& A, vector<int>& cnt, int v, int p, vector<int>& ans) {
    int c = A[v];

    if(cnt[c] == 0) {
        ans.push_back(v);
    }

    cnt[c] += 1;

    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, A, cnt, nei, v, ans);
        }
    }

    cnt[c] -= 1;
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

    vector<int> cnt(100005, 0);
    vector<int> ans;
    dfs(G, A, cnt, 0, -1, ans); 
    
    sort(ans.begin(), ans.end());
    for(int x : ans) {
        cout << x + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
