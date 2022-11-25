#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void dfs(vector<vector<int>>& G, vector<int>& A, vector<multiset<int>>& save, int cur, int pre) {
    multiset<int>& s = save[cur]; 
    s.insert(A[cur]);

    for(int nei : G[cur]) {
        if(nei != pre) {
            dfs(G, A, save, nei, cur); 

            multiset<int>& t = save[nei];
            for(int x : t) {
                s.insert(x);
                if(s.size() > 20) {
                    s.erase(s.begin());
                }
            }
        }
    }
}

void run_case() {
    int N, Q;
    cin >> N >> Q;

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

    vector<multiset<int>> save(N);
    dfs(G, A, save, 0, -1);

    vector<vector<int>> v(N);
    for(int i = 0; i < N; i++) {
        for(int x : save[i]) {
            v[i].push_back(x);
        }
    }

    for(int i = 0; i < Q; i++) {
        int V, K;
        cin >> V >> K;
        V -= 1;
        
        int ans = 0;
        int sz = v[V].size();
        for(int i = 0; i < K; i++) {
            ans = v[V][sz - 1 - i];
        }

        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
