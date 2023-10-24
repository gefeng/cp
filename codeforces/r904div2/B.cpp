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

    std::reverse(S.begin(), S.end());

    std::vector<int64_t> ans;
    int64_t cnt = 0;
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            cnt += 1;
        } else {
            sum += cnt;
            ans.push_back(sum);
        } 
    }

    while(ans.size() < N) {
        ans.push_back(-1);
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
