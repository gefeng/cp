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
    int N, X, Y;
    std::cin >> N >> X >> Y;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) { 
        std::cin >> A[i];
    }

    std::map<int, std::vector<int>> m; 
    for(int x : A) {
        m[x % Y].push_back(x);
    }

    int64_t ans = 0;
    for(auto& [_, v] : m) {
        int n = v.size();
        std::map<int, int> m_cnt;
        for(int i = 0; i < n; i++) {
            int r = (X - (v[i] % X)) % X;
            if(m_cnt.find(r) != m_cnt.end()) {
                ans += m_cnt[r];
            } 
            m_cnt[v[i] % X] += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
