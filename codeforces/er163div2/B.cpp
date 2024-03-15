#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::deque<int> a;

    a.push_back(A.back());
    for(int i = N - 2; i >= 0; i--) {
        if(A[i] > a.front()) {
            int x = A[i];
            std::vector<int> digits;
            while(x) {
                int d = x % 10;
                a.push_front(d);
                x /= 10;
            }
        } else {
            a.push_front(A[i]);
        }
    }
    
    int pre = -1; 
    while(!a.empty()) {
        if(a.front() < pre) {
            std::cout << "No" << '\n';
            return;
        }
        pre = a.front();
        a.pop_front();
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
