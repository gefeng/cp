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

    if(K % 2 == 0) {
        std::sort(S.begin(), S.end());
    } else {
        std::string eve = "";
        std::string odd = "";
        for(int i = 0; i < N; i++) {
            if(i % 2 == 0) {
                eve.push_back(S[i]);
            } else {
                odd.push_back(S[i]);
            }
        }

        std::sort(eve.begin(), eve.end());
        std::sort(odd.begin(), odd.end());

        for(int i = 0, j = 0, k = 0; i < N; i++) {
            if(i % 2 == 0) {
                S[i] = eve[j++];
            } else {
                S[i] = odd[k++];
            }
        }
    }
    std::cout << S << '\n';
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
