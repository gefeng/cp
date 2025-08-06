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

    int cnt = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(S[i] != ')') {
            break;
        }
        cnt += 1;
    }

    std::cout << (cnt > N - cnt ? "Yes" : "No") << '\n';
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
