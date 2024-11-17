#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <map>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::map<int, std::pair<int, int>> m;
    std::vector<int> freq(N, 1);

    for(int i = 0; i < N; i++) {
        m[i] = {i, i};
    }

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
            
        if(T == 1) {
            int P, C;
            std::cin >> P >> C;
            P -= 1;
            C -= 1;

            auto it = m.upper_bound(P);
            it--; 
            int l = it->first;
            int r = it->second.first;
            int c = it->second.second;
            freq[c] -= r - l + 1;
            freq[C] += r - l + 1;
            it->second.second = C;

            auto lhs = it != m.begin() ? std::prev(it) : m.end();
            auto rhs = it != m.end() ? std::next(it) : m.end();

            if(lhs != m.end() && rhs != m.end() && lhs->second.second == C && rhs->second.second == C) {
                lhs->second.first = rhs->second.first;
                m.erase(it);
                m.erase(rhs);
            } else if(lhs != m.end() && lhs->second.second == C) {
                lhs->second.first = it->second.first;    
                m.erase(it);
            } else if(rhs != m.end() && rhs->second.second == C) {
                it->second.first = rhs->second.first;
                m.erase(rhs); 
            }
        } else {
            int C;
            std::cin >> C;
            C -= 1;
            
            std::cout << freq[C] << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
