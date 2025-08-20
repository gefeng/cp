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

    std::string S, T;
    std::cin >> S >> T;

    std::string s(S);

    std::vector<int> ans;
    int now = S[0] - '0';
    for(int i = 1; i < N; i++) {
        if(S[i] - '0' != now) {
            ans.push_back(i);
            now ^= 1;
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        if(T[i] - '0' != now) {
            ans.push_back(i + 1);
            now ^= 1;
        }
    }
    
    int size = ans.size();
    std::cout << size << " \n"[size == 0];
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << " \n"[i == size - 1];
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
