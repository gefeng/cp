#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::string S;
    std::cin >> S;

    std::vector<int> C(N);
    for(int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    std::vector<std::vector<int>> a(M + 1);
    for(int i = 0; i < N; i++) {
        a[C[i]].push_back(i);
    }

    for(int i = 1; i <= M; i++) {
        if(a[i].size()) {
            int last = a[i].back();
            for(int j = a[i].size() - 1; j > 0; j--) {
                a[i][j] = a[i][j - 1];
            }

            a[i][0] = last;
        }
    }

    std::string ans(N, ' ');
    for(int i = 1; i <= M; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            int pre = a[i][(j - 1 + a[i].size()) % a[i].size()];
            int cur = a[i][j];

            ans[cur] = S[pre];
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
