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

    vector<int> H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;

        G[U].push_back(V);
        G[V].push_back(U);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        bool ok = true;
        for(int nei : G[i]) {
            if(H[nei] >= H[i]) {
                ok = false;
                break;
            }
        }

        if(ok) {
            ans += 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
