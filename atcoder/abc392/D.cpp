#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>
#include <iomanip>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> A(N);
    for(int i = 0; i < N; i++) {
        int M;
        std::cin >> M;
        A[i].resize(M, 0);
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        } 
    }

    double ans = 0.0;
    for(int i = 0; i < N; i++) {
        int size_1 = A[i].size();
        std::unordered_map<int, int> m_1;
        for(int x : A[i]) {
            m_1[x] += 1;
        }
        for(int j = i + 1; j < N; j++) {
            int size_2 = A[j].size();
            
            std::unordered_map<int, int> m_2;
            for(int x : A[j]) {
                m_2[x] += 1;
            }

            double p = 0.0;
            for(auto [x, f_2] : m_2) {
                if(m_1.find(x) != m_1.end()) {
                    int f_1 = m_1[x]; 
                    p += (double(f_1) / size_1) * (double(f_2) / size_2);
                }
            }

            ans = std::max(ans, p);
        }
    }

    std::cout << std::setprecision(20) << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
