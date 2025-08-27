#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> a(A);
    std::ranges::sort(A);
    
    int mex = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }
        if(A[j] == mex) {
            mex += 1;
        } else {
            break;
        }
    }

    bool exist = false;
    for(int i = 0; i < N; i++) {
        if(A[i] == mex + 1) {
            exist = true;
            break;
        }
    }

    if(!exist) {
        for(int i = 0; i < N; ) {
            int j = i;
            while(i < N && A[i] == A[j]) {
                i += 1;
            }
            if((A[j] < mex && i - j > 1) || A[j] > mex) {
                std::cout << "Yes" << '\n';
                return;
            }
        }
        std::cout << "No" << '\n';
        return;
    }

    int l = -1;
    int r = -1;
    for(int i = 0; i < N; i++) {
        if(a[i] == mex + 1) {
            l = l == -1 ? i : l;
            r = i;
        } 
    }

    for(int i = l; i <= r; i++) {
        a[i] = mex;
    }

    std::ranges::sort(a);
    
    for(int i = 0, j = 0; i < N && j <= mex; ) {
        int k = i;
        while(i < N && a[i] == a[k]) {
            i += 1;
        }
        if(a[k] != j) {
            std::cout << "No" << '\n';
            return;
        }
        j += 1;
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
