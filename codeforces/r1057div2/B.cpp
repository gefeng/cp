#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, Y, Z;
    std::cin >> X >> Y >> Z;

    std::array<int, 30> a = {};
    std::array<int, 30> b = {};
    std::array<int, 30> c = {};
    a.fill(-1);
    b.fill(-1);
    c.fill(-1);
    
    for(int i = 0; i < 30; i++) {
        if(X & (1 << i)) {
            a[i] = 1;
            b[i] = 1;
        }
    }

    for(int i = 0; i < 30; i++) {
        if(Z & (1 << i)) {
            a[i] = 1;
            c[i] = 1;
        } else {
            if(a[i] == 1) {
                c[i] = 0;
            }
        }
    }

    for(int i = 0; i < 30; i++) {
        if(Y & (1 << i)) {
            if(c[i] == 0) {
                std::cout << "NO" << '\n';
                return;
            }
            b[i] = 1;
            c[i] = 1;
        } else {
            if(b[i] == 1 && c[i] == 1) {
                std::cout << "NO" << '\n';
                return;
            }
            if(b[i] == 1) {
                c[i] = 0;
            } else if(c[i] == 1) {
                b[i] = 0;
            }
        }
    }

    int x = 0;
    int y = 0;
    int z = 0;
    for(int i = 0; i < 30; i++) {
        if(a[i] == 1) {
            x |= 1 << i;
        } 
        if(b[i] == 1) {
            y |= 1 << i;
        } 
        if(c[i] == 1) {
            z |= 1 << i;
        } 
    }

    std::cout << ((x & y) == X && (y & z) == Y && (x & z) == Z ? "YES" : "NO") << '\n';
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
