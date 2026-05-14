#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::ranges::sort(A);

    std::map<int, std::multiset<int>> ml;
    std::map<int, std::multiset<int>> mr;
    for(auto [l, r] : A) {
        ml[l].insert(r - l + 1);
        mr[r].insert(r - l + 1);
    }

    int Q;
    std::cin >> Q;
    std::vector<std::pair<int, int>> B(Q);
    std::vector<int> order(Q, 0);
    for(int i = 0; i < Q; i++) {
        std::cin >> B[i].first >> B[i].second;
        order[i] = i;
    }

    std::ranges::sort(order, [&](int i, int j) {
                return B[i].first > B[j].first;
            });
    
    int min1 = INF;
    int min2 = INF;
    std::vector<int> ans(Q, 0);
    for(int i = 0, j = M - 1; i < Q; i++) {
        auto [L, R] = B[order[i]];
        
        if(ml.find(L) == ml.end() || mr.find(R) == mr.end()) {
            continue;
        } 

        while(j >= 0 && A[j].first >= L) {
            if(A[j].second < min1) {
                min2 = min1;
                min1 = A[j].second;
            } else if(A[j].second < min2) {
                min2 = A[j].second;
            }
            j--;
        }

        int len = R - L + 1;
        auto it1 = ml[L].find(len);
        if(it1 != ml[L].end()) {
            if(min1 < R || (min1 == R && min2 == R)) {
                ans[order[i]] = 1;
            }
            
        } else {
            it1 = ml[L].lower_bound(len);
            if(it1 == ml[L].begin()) {
                continue;
            }
            it1--;

            auto it2 = mr[R].lower_bound(len);
            if(it2 == mr[R].begin()) {
                continue;
            }
            it2--;

            if((*it1) + (*it2) >= len) {
                ans[order[i]] = 1;
            }
        }
    }

    for(int i = 0; i < Q; i++) {
        std::cout << (ans[i] ? "Yes" : "No") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
