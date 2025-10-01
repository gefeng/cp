#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> eve;
    std::vector<int> odd;
    for(int x : A) {
        if(x % 2 == 0) {
            eve.push_back(x);
        } else {
            odd.push_back(x);
        }
    }

    int size = eve.size();
    int ans = 0; 
    if(odd.size() == 0) {
        for(int i = 0; i < size; i++) {
            int cnt = 0;
            while(eve[i] % 2 == 0) {
                eve[i] /= 2;
                cnt += 1;
            }
            eve[i] = cnt;
        }
        std::ranges::sort(eve);
        ans = eve[0] + size - 1;
    } else {
        ans = size;
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
