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

    int ans = 0;
    if(N % 2 == 0) {
        if(B >= A) {
            ans = B % 2 == 0;
        } else {
            ans = A % 2 == 0 && B % 2 == 0;
        }
    } else {
        if(B >= A) {
            ans = B % 2 == 1;
        } else {
            ans = A % 2 == 1 && B % 2 == 1;
        }
    }

    std::cout << (ans ? "Yes" : "No") << '\n';
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
