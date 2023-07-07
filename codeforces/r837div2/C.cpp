#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

int max_v = (int)sqrt(1e9);
std::vector<int> is_prime;
std::vector<int> primes;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::set<int> s;
    for(int x : A) {
        for(int p : primes) {
            if(p > x) {
                break;
            }
            if(x % p == 0) {
                while(x % p == 0) {
                    x /= p;
                }

                if(s.find(p) != s.end()) {
                    std::cout << "YES" << '\n';
                    return;
                }

                s.insert(p);
            }
        }

        if(x > 1) {
            if(s.find(x) != s.end()) {
                std::cout << "YES" << '\n';
                return;
            }
            s.insert(x);
        }
    }

    std::cout << "NO" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    is_prime.resize(max_v + 1, 1);
    for(int i = 2; i <= max_v; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i + i; j <= max_v; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
