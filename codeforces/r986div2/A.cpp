#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, A, B;
    std::cin >> N >> A >> B;
    
    std::string S;
    std::cin >> S;

    int r = 0;
    int c = 0;
    int i = 0;
    int rep = 10000;
    while(rep--) {
        if(r == A && c == B) {
            std::cout << "Yes" << '\n';
            return;
        }
        if(S[i] == 'N') {
            c += 1;
        } else if(S[i] == 'E') {
            r += 1;
        } else if(S[i] == 'S') {
            c -= 1;
        } else {
            r -= 1;
        }

        i = (i + 1) % N;
    }

    std::cout << "No" << '\n';
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
