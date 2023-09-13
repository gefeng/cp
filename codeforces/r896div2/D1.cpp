#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    if(sum % N != 0) {
        std::cout << "NO" << '\n';
        return;
    }

    std::sort(A.begin(), A.end(), std::greater<int>());

    std::set<int64_t> s;
    int64_t p_2 = 1;
    for(int i = 1; i < 40; i++) {
        s.insert(p_2);
        p_2 *= 2;
    }

    int64_t t = sum / N;
    std::map<int64_t, int64_t> m;
    for(int i = 0; i < N; i++) {
        int64_t d = t - A[i];
        
        if(d == 0) {
            continue;
        }
        
        bool found = false;
        for(int64_t x : s) {
            if(s.find(x + d) != s.end()) {
                m[x] += 1;
                m[x + d] -= 1;
                found = true;
                break;
            }
        }

        if(!found) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    for(auto [k, v] : m) {
        if(v != 0) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << "YES" << '\n';
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
