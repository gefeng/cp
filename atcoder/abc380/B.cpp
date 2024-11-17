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

    std::vector<int> ans;
    int n = S.size();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(S[i] == '|') {
            if(cnt) {
                ans.push_back(cnt);
                cnt = 0;
            }
        } else {
            cnt += 1;
        }
    }

    n = ans.size();
    for(int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
