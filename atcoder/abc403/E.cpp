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

constexpr std::array<int64_t, 2> B = {31, 57};
constexpr std::array<int64_t, 2> M = {int64_t(998244353), int64_t(1e9) + 7};

void run_case() {
    int Q;
    std::cin >> Q;

    std::set<std::pair<int64_t, int64_t>> x;
    std::map<std::pair<int64_t, int64_t>, std::set<int>> y;
    std::set<int> valid_y;
    std::set<int> to_remove;
    for(int i = 0; i < Q; i++) {
        int T;
        std::string S;
        
        std::cin >> T >> S;
        
        int n = S.size();
        std::array<int64_t, 2> h = {0, 0};

        if(T == 1) {
            for(int k = 0; k < n; k++) {
                for(int j = 0; j < 2; j++) {
                    h[j] = (h[j] * B[j] % M[j]) + (S[k] - 'a' + 1);
                    h[j] %= M[j];
                }
            }

            std::pair<int64_t, int64_t> key = {h[0], h[1]};
            if(y.find(key) != y.end()) {
                for(int j : y[key]) {
                    to_remove.insert(j);
                }
                y.erase(key);
            }

            x.insert(key);
        } else {
            std::vector<std::pair<int64_t, int64_t>> prefix(n);
            bool good = true;
            for(int k = 0; k < n; k++) {
                for(int j = 0; j < 2; j++) {
                    h[j] = (h[j] * B[j] % M[j]) + (S[k] - 'a' + 1);
                    h[j] %= M[j];
                }
                prefix[k] = {h[0], h[1]};
                if(x.find({h[0], h[1]}) != x.end()) {
                    good = false;
                }
            }
            
            if(good) {
                for(auto [a, b] : prefix) {
                    y[{a, b}].insert(i);
                }  
                valid_y.insert(i);
            }
        }

        for(int j : to_remove) {
            if(valid_y.find(j) != valid_y.end()) {
                valid_y.erase(j);
            }
        }
        
        to_remove.clear();

        std::cout << valid_y.size() << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
