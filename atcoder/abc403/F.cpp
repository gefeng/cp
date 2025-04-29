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
    
    std::vector<std::string> dp_1(N + 1, "");
    std::vector<std::string> dp_2(N + 1, "");

    for(int i = 1; i <= N; i = i * 10 + 1) {
        dp_1[i] = std::to_string(i);
        dp_2[i] = std::to_string(i);
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 1; j < i; j++) {
            int k = i - j;
            if(dp_1[j].empty() || dp_1[k].empty()) {
                continue;
            }
            std::string s = dp_1[j] + "+" + dp_1[k];
            if(dp_1[i].empty() || dp_1[i].size() > s.size()) {
                dp_1[i] = s;
            }
            
            if(dp_2[i].empty() || dp_2[i].size() > s.size() + 2) {
                dp_2[i] = "(" + s + ")";
            }
        }

        for(int j = 2; j * j <= i; j++) {
            if(i % j != 0) {
                continue;
            }

            int k = i / j;
            if(dp_2[j].empty() || dp_2[k].empty()) {
                continue;
            }

            std::string s = dp_2[j] + "*" + dp_2[k];
            if(dp_1[i].empty() || dp_1[i].size() > s.size()) {
                dp_1[i] = s;
            }

            if(dp_2[i].empty() || dp_2[i].size() > s.size()) {
                dp_2[i] = s;
            }
        }
    }

    std::cout << dp_1[N] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
