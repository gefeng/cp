#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

void run_case() {
    int N;
    std::cin >> N;
    
    std::string S;
    std::cin >> S;

    if(N == 2) {
        std::cout << stoi(S) << '\n';
        return;
    }

    int ans = INF;
    for(int i = 0; i < N - 1; i++) {
        int sum = 0;
        for(int j = 0; j < i; j++) {
            if(j == 0) {
                sum += S[j] - '0';
            } else {
                if(sum <= 1 || S[j] == '1' || S[j] == '0') {
                    sum *= S[j] - '0';
                } else {
                    sum += S[j] - '0';
                }
            }
        }

        int x = stoi(S.substr(i, 2));
        if(i != 0 && (sum <= 1 || x <= 1)) {
            sum *= x;
        } else {
            sum += x;
        }
        
        for(int j = i + 2; j < N; j++) {
            if(sum <= 1 || S[j] == '1' || S[j] == '0') {
                sum *= S[j] - '0';
            } else {
                sum += S[j] - '0';
            }
        }    
        ans = std::min(ans, sum);
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
