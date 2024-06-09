#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;
    
    int n = S.size();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(S[i] >= 'a' && S[i] <= 'z') {
            cnt += 1;
        }
    }

    if(cnt > n / 2) {
        for(int i = 0; i < n; i++) {
            if(S[i] < 'a' || S[i] > 'z') {
                S[i] = S[i] - 'A' + 'a'; 
            }
        } 
    } else {
        for(int i = 0; i < n; i++) {
            if(S[i] < 'A' || S[i] > 'Z') {
                S[i] = S[i] - 'a' + 'A';
            }
        }
    }

    std::cout << S << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
