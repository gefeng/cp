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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, std::vector<int>> m_val;
    std::map<int, std::vector<int>> m_pos;
    int mask = (((1 << 30) - 1) >> 2) << 2;
    for(int i = 0; i < N; i++) {
        m_val[A[i] & mask].push_back(A[i]);
        m_pos[A[i] & mask].push_back(i);
    }

    for(auto& [_, v] : m_val) {
        std::sort(v.begin(), v.end());
    }

    std::vector<int> ans(N);
    for(auto& [k, v] : m_val) {
        std::vector<int>& pos = m_pos[k];
        int size = v.size();
        for(int i = 0; i < size; i++) {
            ans[pos[i]] = v[i];
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
