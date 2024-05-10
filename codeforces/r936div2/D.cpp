#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X;
    std::cin >> N >> X;

    X += 1;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = -1;
    std::vector<int> a(A);
    for(int i = 30; i >= 0; i--) {
        int p = 0;
        for(int x : a) {
            if(x & (1 << i)) {
                p ^= 1;            
            }
        }

        if(X & (1 << i)) {
            if(p) {
                continue;
            } 
            
            int n = a.size();
            std::vector<int> pos;
            for(int j = 0; j < n; j++) {
                if(a[j] & (1 << i)) {
                    pos.push_back(j);
                }
            }

            int cnt = 0;
            if(pos.empty()) {
                cnt = a.size();
            } else {
                cnt = pos[0] + (n - pos.back() - 1);

                n = pos.size();
                for(int j = 0; j < n; j += 2) {
                    cnt += 1;
                    if(j) {
                        cnt += pos[j] - pos[j - 1] - 1;
                    }
                }
            }
            ans = std::max(ans, cnt);
        } else {
            if(p) {
                break;
            }

            int n = a.size();
            std::vector<int> na;
            int pre = -1;
            int x = 0;
            for(int j = 0; j < n; j++) {
                if(a[j] & (1 << i)) {
                    x ^= a[j];
                    if(pre == -1) {
                        pre = j;   
                    } else {
                        na.push_back(x);
                        x = 0;
                        pre = -1;
                    }
                } else {
                    if(pre == -1) {
                        na.push_back(a[j]); 
                    } else {
                        x ^= a[j];
                    }
                }
            }

            std::swap(a, na);
        }
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
