#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> A(N - 1);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i <= 100; i++) {
        std::vector<int> a(A);
        a.push_back(i);
        std::sort(a.begin(), a.end());
        
        int sum = 0;
        for(int x : a) {
            sum += x;
        }

        sum -= a.front();
        sum -= a.back();

        if(sum >= X) {
            std::cout << i << '\n';
            return;
        }
    }

    std::cout << -1 << '\n';

    /*std::sort(A.begin(), A.end());

    if(sum - A.back() >= X) {
        std::cout << 0 << '\n';
        return;
    }    

    int ans = 101;
    if(sum - A.front() >= X) {
        ans = std::min(ans, A.back());
    } 
    
    sum -= A.front();
    sum -= A.back();
    
    if(X - sum >= 0 && X - sum <= 100) {
        ans = std::min(ans, X - sum);
    }

    std::cout << (ans == 101 ? -1 : ans) << '\n';*/
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
