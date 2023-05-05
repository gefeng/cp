#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    bool ok = true;
    for(int i = 0, j = N - 1; i < j; i++, j--) {
        if(A[i] != A[j]) {
            ok = false;
            break;
        } 
    } 

    if(ok) {
        std::cout << 0 << '\n';
        return;
    }

    int g = -1;
    for(int i = 0, j = N - 1; i < j; i++, j--) {
        int r = std::max(A[i], A[j]) - std::min(A[i], A[j]);
        if(g == -1) {
            g = r;
        } else {
            g = gcd(g, r);
        }
    }

    std::cout << g << '\n';
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
