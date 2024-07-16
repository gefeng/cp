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
    int cnt_0 = 0;
    for(int i = 0; i < N; ) {
        if(S[i] == '1') {
            cnt_1 += 1;
            i += 1;
        } else {
            while(i < N && S[i] == '0') {
                i += 1;
            }
            cnt_0 += 1;
        }
    }

    std::cout << (cnt_1 > cnt_0 ? "Yes" : "No") << '\n';
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
