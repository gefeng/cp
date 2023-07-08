#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::map<int, int64_t> m;
    int last = 0;
    for(auto& p : A) {
        m[p.first] += p.second;
        last = std::max(last, p.first);
    }

    auto it = m.end();
    it--;
    int ans = last + 1;
    int64_t sum = 0;
    while(true) {
        if(sum <= K && sum + it->second > K) {
            ans = it->first + 1;
        }
        sum += it->second;

        if(it == m.begin()) {
            break;
        }
        it--;
    }

    if(sum <= K) {
        std::cout << 1 << '\n';
        return;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
