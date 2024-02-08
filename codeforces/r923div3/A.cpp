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

    int first = -1;
    int end = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'B') {
            if(first == -1) {
                first = i;
            }
            end = i;
        }
    }

    std::cout << (first == -1 ? 0 : end - first + 1) << '\n';
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
