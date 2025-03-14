#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ctime>

void run_case() {
    int N;
    std::cin >> N;
    
    auto query = [](int i, int j, int k) {
        std::cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    auto output = [](int i, int j, int k) {
        std::cout << "! " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << std::endl;
        return;
    };

    std::array<int, 3> a;
    while(true) {
        int x = std::rand() % N;
        int y = std::rand() % N;
        int z = std::rand() % N;
        if(x == y || y == z || x == z) {
            continue;
        }
        a[0] = x;
        a[1] = y;
        a[2] = z;
        break;
    }

    while(true) {
        int q = query(a[0], a[1], a[2]);
        if(q == 0) {
            output(a[0], a[1], a[2]);
            return;
        }
        if(q == -1) {
            return;
        }

        q--;
        int x = std::rand() % 3;
        for(int i = 0; i < 3; i++) {
            if(x == i) {
                a[i] = q;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::srand(std::time(nullptr));
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
