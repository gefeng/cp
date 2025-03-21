#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::set<int> s;
    int mid = A[0];
    s.insert(mid);

    for(int i = 1; i < N; i++) {
        if(A[i] == mid) {
            continue;
        }
        
        if(A[i] > mid) {
            auto it = s.lower_bound(A[i]);
            if(*std::prev(it) != mid) {
                std::cout << "No" << '\n';
                return;
            }
        } else {
            auto it = s.upper_bound(A[i]);
            if(*it != mid) {
                std::cout << "No" << '\n';
                return;
            }
        }

        s.insert(A[i]);
        mid = A[i];
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
