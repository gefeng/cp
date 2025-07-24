#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    std::vector<std::pair<int, int>> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> B[i].first;
        A[i].second = i;
        B[i].second = i;
    }

    std::ranges::sort(A, [](const auto& a, const auto& b) {
                return a.first < b.first;
            });
    std::ranges::sort(B, [](const auto& a, const auto& b) {
                return a.first < b.first;
            });

    std::vector<int> on_l(N, -1);
    std::vector<int> on_r(N, -1);
    std::vector<int> l;
    std::vector<int> r;
    std::vector<int> lr;
    std::vector<int> rl;
    std::vector<int> matched(N, 0);
    for(int i = 0; i < N; i++) {
        if(i < N / 2) {
            on_l[A[i].second] = i;
        } else {
            on_r[A[i].second] = i;
        }
    }
    
    for(int i = 0; i < N / 2; i++) {
        if(on_l[B[i].second] != -1) {
            l.push_back(B[i].second);
        } else {
            rl.push_back(B[i].second);
        }
    }

    for(int i = N / 2; i < N; i++) {
        if(on_r[B[i].second] != -1) {
            r.push_back(B[i].second);
        } else {
            lr.push_back(B[i].second);
        }
    }

    while(!l.empty() && !r.empty()) {
        std::cout << l.back() + 1 << ' ' << r.back() + 1 << '\n';
        l.pop_back();
        r.pop_back();
    }

    while(!lr.empty() && !rl.empty()) {
        std::cout << lr.back() + 1 << ' ' << rl.back() + 1 << '\n';
        lr.pop_back();
        rl.pop_back();
    }

    assert(l.empty() && r.empty() && lr.empty() && rl.empty());
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
