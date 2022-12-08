#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    vector<int> ind(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        ind[V] += 1;
    }

    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++) {
        if(ind[i] == 0) {
            pq.push(i);
        }
    }

    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        ans.push_back(cur);

        for(int nei : G[cur]) {
            if(--ind[nei] == 0) {
                pq.push(nei);
            }
        }
    }

    if(ans.size() != N) {
        cout << -1 << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] + 1 << " \n"[i == N - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
