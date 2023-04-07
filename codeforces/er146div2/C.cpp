#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, S1, S2;
    std::cin >> N >> S1 >> S2;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::sort(A.begin(), A.end(), std::greater<std::pair<int, int>>());

    std::vector<int> ans_a;
    std::vector<int> ans_b;

    int t_a = S1;
    int t_b = S2;
    for(auto& p : A) {
        int b = p.second;

        if(t_a <= t_b) {
            ans_a.push_back(b + 1);
            t_a += S1;
        } else {
            ans_b.push_back(b + 1);
            t_b += S2;
        }
    }

    int sz = ans_a.size();
    std::cout << sz << " \n"[sz == 0];
    for(int i = 0; i < sz; i++) {
        std::cout << ans_a[i] << " \n"[i == sz - 1];
    }

    sz = ans_b.size();
    std::cout << sz << " \n"[sz == 0];
    for(int i = 0; i < sz; i++) {
        std::cout << ans_b[i] << " \n"[i == sz - 1];
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
