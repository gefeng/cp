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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 1; i <= X * 2; i++) {
        bool ok = true;
        int pre = 0;
        for(int x : A) {
            if(x - pre > i) {
                ok = false;
                break;
            }
            pre = x;
        }

        if(!ok) {
            continue;
        }

        if((X - pre) * 2 > i) {
            ok = false;
        }

        if(!ok) {
            continue;
        }

        pre = A.back();
        for(int j = N - 2; j >= 0; j--) {
            if(pre - A[j] > i) {
                ok = false;
                break;
            }
            pre = A[j];
        }

        if(!ok) {
            continue;
        }

        if(pre > i) {
            ok = false;
        }

        if(ok) {
            std::cout << i << '\n';
            return;
        }
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
