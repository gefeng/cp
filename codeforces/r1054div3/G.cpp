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
#include <unordered_set>
#include <chrono>
#include <random>

constexpr int MAX = 40;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    std::map<int, std::vector<int>> pos;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos[A[i]].push_back(i);
    } 

    auto get_freq = [&](int x, int l, int r) {
        std::vector<int>& a = pos[x]; 
        return std::upper_bound(a.begin(), a.end(), r) - std::lower_bound(a.begin(), a.end(), l);
    };

    
    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;

        L -= 1;
        R -= 1;

        int len = R - L + 1;

        std::map<int, int> freq;
        std::vector<int> ans;
        if(len <= MAX) {
            for(int j = L; j <= R; j++) {
                freq[A[j]] += 1;
            }
            for(auto [x, f] : freq) {
                if(f > len / 3) {
                    ans.push_back(x);
                }
            }
        } else {
            int b = len / MAX;
            int rem = len % MAX;
            for(int j = 0, p = 0; j < MAX; j++) {
                int l = p;
                int r = l + b - 1 + (rem ? 1 : 0);
                int idx = std::uniform_int_distribution<int>(l, r)(rng) + L;
                if(rem) {
                    rem -= 1;
                }
                freq[A[idx]] += 1; 
                p = r + 1;
            }
            
            std::vector<std::pair<int, int>> a;
            for(auto [x, f] : freq) {
                a.emplace_back(f, x);
            }

            std::ranges::sort(a);
            
            for(int i = a.size() - 1, j = 5; i >= 0 && j >= 0; i--, j--) {
                auto [_, x] = a[i];
                int f = get_freq(x, L, R);
                if(f > len / 3) {
                    ans.push_back(x);
                }
            }
        }

        std::ranges::sort(ans);

        if(ans.empty()) {
            std::cout << -1 << '\n';
        } else {
            int size = ans.size();
            for(int j = 0; j < size; j++) {
                std::cout << ans[j] << " \n"[j == size - 1];
            }
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
