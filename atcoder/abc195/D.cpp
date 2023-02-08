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
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    vector<int> B(M);
    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }

    auto cmp = [](const auto& a, const auto& b) {
        if(a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    };

    sort(A.begin(), A.end(), cmp);

    for(int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;

        L -= 1;
        R -= 1;

        map<int, int> m;
        for(int j = 0; j < L; j++) {
            m[B[j]] += 1;
        }
        for(int j = R + 1; j < M; j++) {
            m[B[j]] += 1;
        }

        int res = 0;
        for(auto& p : A) {
            int w = p.first;
            int v = p.second;

            auto it = m.lower_bound(w);
            if(it != m.end()) {
                res += v;
                if(--it->second == 0) {
                    m.erase(it);
                }
            }
        }

        cout << res << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
