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
    int W, H, N;
    std::cin >> W >> H >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
        A[i].first -= 1;
        A[i].second -= 1;
    }

    int P;
    std::cin >> P;
    std::vector<int> B(P);
    for(int i = 0; i < P; i++) {
        std::cin >> B[i];
    }
    B.push_back(W);

    int Q;
    std::cin >> Q;
    std::vector<int> C(Q);
    for(int i = 0; i < Q; i++) {
        std::cin >> C[i];
    }
    C.push_back(H);

    std::map<std::pair<int, int>, int> m;
    for(auto& s : A) {
        int x = s.first;
        int y = s.second;

        auto it1 = upper_bound(B.begin(), B.end(), x);
        auto it2 = upper_bound(C.begin(), C.end(), y); 
        
        m[{*it1, *it2}] += 1;
    }

    int min_v = N;
    int max_v = 0;
    for(auto [k, v] : m) {
        min_v = std::min(min_v, v);
        max_v = std::max(max_v, v);
    }

    int64_t tot = (int64_t)(P + 1) * (Q + 1);
    if(tot > m.size()) {
        min_v = 0;
    }

    std::cout << min_v << ' ' << max_v << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
