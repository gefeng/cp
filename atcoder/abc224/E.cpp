#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

void run_case() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<pair<int, int>> P(N);
    map<int, vector<pair<int, int>>> m;
    for(int i = 0; i < N; i++) {
        int X, Y, A;
        cin >> X >> Y >> A;
        X -= 1;
        Y -= 1;

        P[i] = {X, Y};
        m[-A].emplace_back(X, Y);
    }

    map<pair<int, int>, int> ans;
    map<int, int> mr;
    map<int, int> mc;
    for(auto& [k, v] : m) {
        for(auto& [r, c] : v) {
            ans[{r, c}] = max(mr[r], mc[c]) + 1;
        }
        for(auto& [r, c] : v) {
            mr[r] = max(ans[{r, c}], mr[r]);
            mc[c] = max(ans[{r, c}], mc[c]);
        }
    }

    for(int i = 0; i < N; i++) {
        cout << ans[P[i]] - 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
