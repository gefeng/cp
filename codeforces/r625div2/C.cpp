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

    for(char c = 'z'; c >= 'a'; c--) {
        std::string s = "";
        int n = S.size();
        
        for(int i = 0; i < n; ) {
            if(S[i] == c) {
                int j = i;
                while(i < n && S[i] == S[j]) {
                    i += 1;
                }
                if((j && S[j - 1] + 1 == c) || (i < n && S[i] + 1 == c)) {
                } else {
                    for(int k = j; k < i; k++) {
                        s.push_back(S[k]);
                    }
                }
            } else {
                s.push_back(S[i]);
                i += 1;
            }
        }
        S = std::move(s);
    }

    std::cout << N - S.size() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
