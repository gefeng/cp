#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using LL = long long;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::array<int, 3>> A(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> A[i][j];
        }
    }

    std::map<int, std::map<int, int>> cm;
    std::map<int, LL> rsum;
    std::map<int, LL> csum;

    for(int i = 0; i < N; i++) {
        int r = A[i][0];
        int c = A[i][1];
        int v = A[i][2];

        cm[c][r] = v;
        rsum[r] += v;
        csum[c] += v;
    }

    std::vector<std::pair<LL, int>> sorted;
    for(auto [c, cs] : csum) {
        sorted.emplace_back(cs, c);
    }

    std::sort(sorted.begin(), sorted.end(), std::greater<std::pair<LL, int>>());

    LL ans = 0LL;
    for(auto [r, s] : rsum) {
        LL max_s = 0LL;

        auto it = sorted.begin();
        while(it != sorted.end()) {
            LL cs = it->first;
            int c = it->second;

            if(cm[c].find(r) == cm[c].end()) {
                max_s = std::max(max_s, cs + s);
                break;
            }

            max_s = std::max(max_s, cs + s - cm[c][r]);

            it++;
        }

        ans = std::max(ans, max_s);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
