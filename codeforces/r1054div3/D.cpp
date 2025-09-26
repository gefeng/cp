#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    auto solve = [&](char t) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(S[i] == t) {
                cnt += 1;
            }
        }
        
        int m = (cnt + 1) / 2;
        int p = -1;
        for(int i = 0; i < N; i++) {
            if(S[i] == t) {
                if(--m == 0) {
                    p = i;
                    break;
                }
            }
        }

        int64_t res = 0;
        int offset = 0;
        for(int i = p - 1; i >= 0; i--) {
            if(S[i] == t) {
                res += p - offset - i - 1; 
                offset += 1;
            }
        }

        offset = 0;
        for(int i = p + 1; i < N; i++) {
            if(S[i] == t) {
                res += i - (p + offset) - 1;
                offset += 1;
            }
        }
        return res;
    };

    std::cout << std::min(solve('a'), solve('b')) << '\n';
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
