#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, A, B, C;
    std::cin >> N >> A >> B >> C;
    
    int sum = A + B + C;
    
    int ans = N / sum * 3;
    int rem = N % sum; 

    if(rem > 0) {
        rem -= A;
        ans += 1;
    }
    if(rem > 0) {
        rem -= B;
        ans += 1;
    }
    if(rem > 0) {
        ans += 1;
    }
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
