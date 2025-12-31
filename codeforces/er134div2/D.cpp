#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

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

    std::vector<std::vector<int>> a;
    std::vector<std::vector<int>> b;
    std::vector<int> tmp(N, 0);
    std::iota(tmp.begin(), tmp.end(), 0);
    a.push_back(tmp);
    b.push_back(B);

    int ans = 0;
    for(int bit = 29; bit >= 0; bit--) {
        bool split = true;
        for(int k = 0; k < a.size(); k++) {
            int n = a[k].size();
            std::array<int, 2> c1 = {};
            std::array<int, 2> c2 = {};
            for(int i = 0; i < n; i++) {
                int j = a[k][i];
                int v = b[k][i];
                int b1 = A[j] & (1 << bit) ? 1 : 0;
                int b2 = v & (1 << bit) ? 1 : 0;
                c1[b1] += 1;
                c2[b2] += 1;
            }
    
            if(c1[0] != c2[1] || c1[1] != c2[0]) {
                split = false;
                break;
            }
        }
        if(!split) {
            continue;
        }
        ans |= 1 << bit;
        
        std::vector<std::vector<int>> nxt_a;
        std::vector<std::vector<int>> nxt_b;
        for(int k = 0; k < a.size(); k++) {
            int n = a[k].size();
            std::vector<int> a1;
            std::vector<int> a2;
            std::vector<int> b1;
            std::vector<int> b2;
            for(int i = 0; i < n; i++) {
                int j = a[k][i];
                int v = b[k][i];
                if(A[j] & (1 << bit)) {
                    a2.push_back(j);    
                } else {
                    a1.push_back(j);
                }
                if(v & (1 << bit)) {
                    b2.push_back(v);
                } else {
                    b1.push_back(v);
                }
            }
            if(!a1.empty()) {
                nxt_a.push_back(a1);
                nxt_b.push_back(b2);
            }
            if(!a2.empty()) { 
                nxt_a.push_back(a2);
                nxt_b.push_back(b1);
            }
        }
        a = std::move(nxt_a);
        b = std::move(nxt_b);
    }

    std::cout << ans << '\n';
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
