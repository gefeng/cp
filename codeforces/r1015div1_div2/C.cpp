#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == B[i]) {
            cnt += 1;
        }
    }

    if((N % 2 == 0 && cnt) || (N % 2 == 1 && cnt != 1)) {
        std::cout << -1 << '\n';
        return;
    }

    std::set<std::pair<int, int>> s;
    for(int i = 0; i < N; i++) {
        if(A[i] == B[i]) {
            continue;
        }
        std::pair<int, int> rev = {B[i], A[i]};

        if(s.find(rev) != s.end()) {
            s.erase(rev);
            continue;
        }

        s.emplace(A[i], B[i]);
    }

    if(!s.empty()) {
        std::cout << -1 << '\n';
        return;
    }

    std::map<std::pair<int, int>, int> m_1;
    std::map<int, std::pair<int, int>> m_2;
    std::vector<std::pair<int, int>> ans;
    int mid = -1;
    for(int i = 0; i < N; i++) {
        m_1[{A[i], B[i]}] = i;
        m_2[i] = {A[i], B[i]};
        if(A[i] == B[i]) {
            mid = i; 
        }
    }

    auto swap = [&](int i, int j) {
        auto [a, b] = m_2[i];
        auto [x, y] = m_2[j];
        
        m_2[i] = {x, y};
        m_2[j] = {a, b};

        m_1[{a, b}] = j;
        m_1[{x, y}] = i;

        std::swap(A[i], A[j]);
        std::swap(B[i], B[j]);
        ans.emplace_back(i, j); 
    };

    if(mid != -1 && mid != N / 2) {
        swap(mid, N / 2);
    }

    for(int i = 0; i < N / 2; i++) {
        auto [a, b] = m_2[i];
        
        int j = m_1[{b, a}];
        if(j != N - 1 - i) {
            swap(j, N - 1 - i);
        }
    }

    int k = ans.size();
    std::cout << k << '\n';
    for(int i = 0; i < k; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }

    for(int i = 0; i < N / 2; i++) {
        assert(A[i] == B[N - 1 - i] && B[i] == A[N - 1 - i]);
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
