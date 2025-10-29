#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <queue>
#include <set>

void run_case() {
    int N, K, X;
    std::cin >> N >> K >> X;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    std::priority_queue<std::pair<int, int>> pq;
    std::set<int> s;
    std::vector<int> ans;

    for(int i = 0; i < N - 1; i++) {
        int d = A[i + 1] - A[i];
        int p = A[i] + d / 2;
        for(int j = -1; j <= 1; j++) {
            int np = p + j;
            if(np >= A[i] && np <= A[i + 1] && s.find(np) == s.end()) {
                pq.emplace(std::min(np - A[i], A[i + 1] - np), np);
                s.insert(np);
            }
        }
    }

    if(s.find(0) == s.end()) {
        pq.emplace(A[0], 0);
        s.insert(0);
    }
    if(s.find(X) == s.end()) {
        pq.emplace(X - A.back(), X);
        s.insert(X);
    }

    while(!pq.empty() && ans.size() < K) {
        auto [d, p] = pq.top();
        pq.pop();
        ans.push_back(p);
        
        for(int i = -1; i <= 1; i += 2) {
            int np = i + p;
            if(np >= 0 && np <= X && s.find(np) == s.end()) {
                auto it = std::lower_bound(A.begin(), A.end(), np); 
                if(it == A.end()) {
                    pq.emplace(np - A.back(), np);
                } else {
                    int dr = *it - np;
                    if(it == A.begin()) {
                        pq.emplace(dr, np);
                    } else {
                        it--;
                        int dl = np - *it;
                        pq.emplace(std::min(dl, dr), np);
                    }
                }
                s.insert(np);
            }
        }
    }

    assert(K == ans.size());

    for(int i = 0; i < K; i++) {
        std::cout << ans[i] << " \n"[i == K - 1];
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
