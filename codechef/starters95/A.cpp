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
    
    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int cnt_a = 0;
    int cnt_b = 0;
    int cnt_ab = 0;
    int cnt_o = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == "A") {
            cnt_a += 1;  
        } else if(A[i] == "B") {
            cnt_b += 1;
        } else if(A[i] == "AB") {
            cnt_ab += 1;
        } else {
            cnt_o += 1;
        }
    }

    int ans = std::max(cnt_a + cnt_ab + cnt_o, cnt_b + cnt_ab + cnt_o);
    
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
