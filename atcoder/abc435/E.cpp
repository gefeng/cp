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
    int N, Q;
    std::cin >> N >> Q;

    auto overlap = [](int l1, int r1, int l2, int r2) {
        if(l1 > l2) {
            std::swap(l1, l2);
            std::swap(r1, r2);
        }
        return l2 <= r1 + 1;
    };

    std::map<int, int> m;
    int black = 0;
    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        auto it = m.lower_bound(L);

        if(it != m.begin() && std::prev(it)->second + 1 >= L) {
            it--;
        } else if(it != m.end() && it->first <= R + 1) {
             
        } else {
            black += R - L + 1;
            m[L] = R;
            std::cout << N - black << '\n';
            continue;
        }

        std::vector<std::pair<int, int>> covered;
        while(it != m.end()) {
            if(overlap(it->first, it->second, L, R)) {
                covered.emplace_back(it->first, it->second);
                it++;
            } else {
                break;
            }
        }

        int cnt_b = 0;
        int pre = -1;
        for(auto [l, r] : covered) {
            m.erase(l);
            if(pre != -1) {
                cnt_b += l - pre - 1;
            }
            pre = r;
        }
        if(L < covered[0].first) {
            cnt_b += covered[0].first - L;
        } 
        if(R > pre) {
            cnt_b += R - pre;
        }

        m[std::min(L, covered[0].first)] = std::max(R, pre);
        black += cnt_b;

        std::cout << N - black << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
