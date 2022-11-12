#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool is_colinear(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int x_1 = b.first - a.first;
    int y_1 = b.second - a.second;
    int x_2 = c.first - a.first;
    int y_2 = c.second - a.second; 

    int cross_prod = x_1 * y_2 - y_1 * x_2;
    return cross_prod == 0;
}

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    if(K == 1) {
        cout << "Infinity" << '\n';
        return;
    }

    map<int, int> m;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }
            int cnt = 2;
            for(int k = 0; k < N; k++) {
                if(k != i && k != j) {
                    if(is_colinear(A[i], A[j], A[k])) {
                        cnt += 1;
                    }
                }
            }

            if(cnt >= K) {
                m[cnt] += 1;
            }
        }
    }

    int ans = 0;
    for(auto [k, v] : m) {
        ans += v / ((k - 1) * k);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
