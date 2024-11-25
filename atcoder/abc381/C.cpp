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
    
    int cnt_1 = 0;
    int ans = 0;
    for(int i = 0; i < N; ) {
        if(S[i] == '1') {
            cnt_1 += 1;
            i += 1;
        } else if(S[i] == '/') {
            int cnt_2 = 0;
            i += 1;
            while(i < N && S[i] == '2') {
                cnt_2 += 1; 
                i += 1;
            }
            ans = std::max(ans, 1 + std::min(cnt_1, cnt_2) * 2);
            cnt_1 = 0;
        } else {
            cnt_1 = 0;
            i += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
