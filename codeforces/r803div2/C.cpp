#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    auto trim_zero = [&]() {
        std::vector<int64_t> a;
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] == 0) {
                cnt += 1;
                if(cnt <= 3) {
                    a.push_back(A[i]);
                }
            } else {
                a.push_back(A[i]);
            }
        }
        A = std::move(a);
    };

    trim_zero();
    N = A.size();

    int64_t a = A[0] + A[1] + A[2];
    int64_t b = A[N - 1] + A[N - 2] + A[N - 3];
    
    bool found_a = false;
    bool found_b = false;
    for(int i = 0; i < N; i++) {
        if(A[i] == a) {
            found_a = true;
        }
        if(A[i] == b) {
            found_b = true;
        }
    }    

    if(!found_a || !found_b) {
        std::cout << "No" << '\n';
        return;
    }

    std::set<int64_t> s(A.begin(), A.end());
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            for(int k = j + 1; k < N; k++) {
                if(s.find(A[i] + A[j] + A[k]) == s.end()) {
                    std::cout << "No" << '\n';
                    return;
                }
            }
        }
    } 

    std::cout << "Yes" << '\n';
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
