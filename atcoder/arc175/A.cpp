#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::string S;
    std::cin >> S;

    auto count = [&](std::string s, int clockwise) {
        std::vector<int> l(N, 0);
        std::vector<int> r(N, 0);
        int64_t res = 1;
        
        for(int i = 0; i < N; i++) {
            if(s[A[i]] == '?') {
                if(!l[A[i]] && !r[A[i]]) {
                    s[A[i]] = clockwise ? 'L' : 'R';
                    if(s[A[i]] == 'R') {
                        l[(A[i] + 1) % N] = 1;
                        r[A[i]] = 1;
                    } else {
                        r[(A[i] - 1 + N) % N] = 1;
                        l[A[i]] = 1;
                    }
                } else if(l[A[i]] && r[A[i]]) {
                    return (int64_t)0;
                } else {
                    res *= 2;
                    res %= MOD;
                    if(l[A[i]]) {
                        l[(A[i] + 1) % N] = 1;
                        r[A[i]] = 1;
                    } else {
                        r[(A[i] - 1 + N) % N] = 1;
                        l[A[i]] = 1;
                    }
                }
            } else {
                if(!l[A[i]] && !r[A[i]]) {
                    if((clockwise && s[A[i]] == 'R') || (!clockwise && s[A[i]] == 'L')) {
                        return (int64_t)0;
                    }
                    
                    if(s[A[i]] == 'R') {
                        l[(A[i] + 1) % N] = 1;
                        r[A[i]] = 1;
                    } else {
                        r[(A[i] - 1 + N) % N] = 1;
                        l[A[i]] = 1;
                    }
                } else if(l[A[i]] && r[A[i]]) {
                    return (int64_t)0;
                } else {
                    if(l[A[i]]) {
                        l[(A[i] + 1) % N] = 1;
                        r[A[i]] = 1;
                    } else {
                        r[(A[i] - 1 + N) % N] = 1;
                        l[A[i]] = 1;
                    }
                }
            }
        } 

        return res;
    };

    int64_t ans = 0;
    if(S[A[0]] == '?') {
        for(int i = 0; i < 2; i++) {
            ans += count(S, i);
            ans %= MOD;
        }
    } else {
        ans += count(S, S[A[0]] == 'L' ? 1 : 0); 
        ans %= MOD;
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
