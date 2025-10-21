#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int cnt = 0;
    int a = -1;
    int b = -1;
    int c = -1;
    int p = -1;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }
        if(i - j == 4) {
            for(int i = 0; i < 4; i++) {
                std::cout << A[j] << " \n"[i == 3];
            }
            return;
        }
        if(i - j == 3) {
            if(cnt) {
                std::cout << a << ' ' << A[j] << ' ' << A[j] << ' ' << A[j] << '\n';
                return;
            } 
        }
        if(i - j > 1) {
            if(cnt > 1) {
                std::cout << a << ' ' << b << ' ' << A[j] << ' ' << A[j] << '\n';
                return;
            }
            a = A[j];
            b = A[j];
            c = A[j];
            p = j;
            cnt += 2;
        } else {
            cnt += 1;
            if(a == -1) {
                a = A[j];
            } else {
                b = A[j];
            }
        }
    }

    if(p == -1) {
        std::cout << -1 << '\n';
        return;
    }

    A.erase(A.begin() + p);
    A.erase(A.begin() + p);
    
    int x = c + c;
    for(int i = 0; i < N - 2; i++) {
        auto it = std::lower_bound(A.begin() + i + 1, A.end(), x + A[i]);
        if(it != A.begin()) {
            int j = std::prev(it) - A.begin();
            if(j > i) {
                std::cout << c << ' ' << c << ' ' << A[i] << ' ' << A[j] << '\n';
                return;
            }
        }
    }

    std::cout << -1 << '\n';
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
