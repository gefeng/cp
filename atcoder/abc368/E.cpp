#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::array<int, 4>> events;
    std::vector<int64_t> ans(M, 0);
    std::vector<int64_t> arrive(N, 0);
    for(int i = 0; i < M; i++) {
        int U, V, S, T;
        std::cin >> U >> V >> S >> T;
        U -= 1;
        V -= 1;
        
        events.push_back({S, 0, U, i});
        events.push_back({T, 1, V, i});
    }

    std::sort(events.begin(), events.end(), [](const auto& a, const auto b) {
                if(a[0] == b[0]) {
                    return a[1] > b[1];
                }            
                return a[0] < b[0];
            });

    ans[0] = K;
    for(std::array<int, 4> e : events) {
        if(e[1] == 0) {
            ans[e[3]] = std::max(ans[e[3]], std::max(int64_t(0), arrive[e[2]] - e[0]));
        } else {
            arrive[e[2]] = std::max(arrive[e[2]], e[0] + ans[e[3]]);
        }
    }

    for(int i = 1; i < M; i++) {
        std::cout << ans[i] << " \n"[i == M - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
