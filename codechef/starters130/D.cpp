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

    std::vector<int> ans;
    for(int i = 1; i < N; i += 2) {
        if(S[i] != S[i - 1]) {
            if(ans.empty()) {
                ans.push_back(i);
            } else {
                if(S[ans.back()] == '0') {
                    ans.push_back(S[i] == '1' ? i : i - 1);
                } else {
                    ans.push_back(S[i] == '1' ? i - 1 : i);
                }
            }
        } 
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] + 1 << " \n"[i == size - 1];
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
