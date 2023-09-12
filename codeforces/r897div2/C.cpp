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

    int mex = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] != mex) {
            break;
        }
        mex += 1;
    }

    auto query = [](int x) {
        std::cout << x << std::endl;
        int res;
        std::cin >> res;
        return res;
    };

    int add = mex;
    while(true) {
        int res = query(add); 
        if(res < 0) {
            break;        
        }

        add = res;
    }

    std::cout << std::endl;
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
