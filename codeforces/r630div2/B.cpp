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

    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    std::vector<int> color(N, 0);
    std::vector<int> used(11, 0);    
    int c = 1;
    for(int i = 0; i < 11; i++) {
        bool found = false;
        for(int j = 0; j < N; j++) {
            if(!color[j] && A[j] % primes[i] == 0) {
                color[j] = c;
                found = true;
            } 
        }
        if(found) {
            c += 1;
        }
    }

    std::cout << c - 1 << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << color[i] << " \n"[i == N - 1];
    }
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
