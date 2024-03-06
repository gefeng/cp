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

    std::vector<int> a(A);
    std::sort(a.begin(), a.end());

    int mex = 0;
    for(int i = 0; i < N; i++) {
        if(a[i] == mex) {
            mex += 1;
        }
    }

    if(mex == 0) {
        std::cout << 2 << '\n';
        std::cout << 1 << ' ' << N - 1 << '\n';
        std::cout << N << ' ' << N << '\n';
        return;
    }

    std::set<int> s;
    int p = 0;
    int p1 = 0;
    while(p < N && s.size() != mex) {
        if(A[p] < mex) {
            s.insert(A[p]);
        }
        p += 1;
    }

    if(p == N) {
        std::cout << -1 << '\n';
        return;
    }
    
    p1 = p - 1;

    s.clear();
    while(p < N) {
        if(A[p] < mex) {
            s.insert(A[p]);
        }
        p += 1;
    }

    if(s.size() != mex) {
        std::cout << -1 << '\n';
        return;
    } 

    std::cout << 2 << '\n';
    std::cout << 1 << ' ' << p1 + 1 << '\n' << p1 + 2 << ' ' << N << '\n';
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
