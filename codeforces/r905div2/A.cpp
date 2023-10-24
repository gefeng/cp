#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::string S;
    std::cin >> S;

    std::array<int, 26> cnt = {};
    for(char c : S) {
        cnt[c - 'a'] += 1;
    }

    if((N - K) % 2 == 0) {
        for(int i = 0; i < 26; i++) {
            if(cnt[i] % 2 == 1 && K) {
                K -= 1;
                cnt[i] -= 1;
            }        
        }

        if(K == 0) {
            for(int i = 0; i < 26; i++) {
                if(cnt[i] % 2 == 1) {
                    std::cout << "No" << '\n';
                    return;
                }
            } 
            std::cout << "Yes" << '\n';
        } else {
            std::cout << (K % 2 == 0 ? "Yes" : "No") << '\n';
        }
    } else {
        for(int i = 0; i < 26; i++) {
            if(cnt[i] % 2 == 1 && K) {
                K -= 1;
                cnt[i] -= 1;
            }        
        }

        if(K == 0) {
            int odd = 0;
            for(int i = 0; i < 26; i++) {
                if(cnt[i] % 2 == 1) {
                    odd += 1;
                }
            }

            std::cout << (odd < 2 ? "Yes" : "No") << '\n';
        } else {
            std::cout << "Yes" << '\n';
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
