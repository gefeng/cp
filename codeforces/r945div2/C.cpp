#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto solve = [&](int st) {
        std::vector<std::pair<int, int>> a;
        std::vector<std::pair<int, int>> b;
        std::vector<int> taken(N, 0);
        for(int i = st; i < N - 1; i += 2) {
            a.emplace_back(A[i], i);
            taken[i] = 1;
        }

        for(int i = 0; i < N; i++) {
            if(!taken[i]) {
                b.emplace_back(A[i], i);
            } 
        }

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        
        std::vector<int> q(N, 0);
        int cur = N;
        for(auto [v, i] : a) {
            q[i] = cur;
            cur -= 1;
        }
        for(auto [v, i] : b) {
            q[i] = cur;
            cur -= 1;
        }

        return q;
    };

    std::vector<int> q1 = solve(1);
    std::vector<int> q2 = solve(2);
    
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 1; i < N - 1; i += 2) {
        if(q1[i] + A[i] > q1[i - 1] + A[i - 1] && q1[i] + A[i] > q1[i + 1] + A[i + 1]) {
            cnt1 += 1;
        }
    }

    for(int i = 2; i < N - 1; i += 2) {
        if(q2[i] + A[i] > q2[i - 1] + A[i - 1] && q2[i] + A[i] > q2[i + 1] + A[i + 1]) {
            cnt2 += 1;
        }
    }

    if(cnt1 > cnt2) {
        for(int i = 0; i < N; i++) {
            std::cout << q1[i] << " \n"[i == N - 1];
        } 
    } else {
        for(int i = 0; i < N; i++) {
            std::cout << q2[i] << " \n"[i == N - 1];
        } 
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
