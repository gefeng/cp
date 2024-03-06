#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    auto query = [](int x, int y) {
        std::cout << "? " << x << ' ' << y << std::endl;
        int res;
        std::cin >> res;
        return res;
    };

    int d = query(1, 1);
    
    int qx1 = d >= M ? d + 2 - M : 1;
    int qy1 = d >= M ? M : d + 2 - 1;
    int qx2 = d >= N ? N : d + 2 - 1;
    int qy2 = d >= N ? d + 2 - N : 1;

    int x = 0;
    int y = 0;
    int d1 = query(qx1, qy1);
    int d2 = query(qx2, qy2);
    if((d1 + 2 * qx1) % 2 == 0) {
        x = (d1 + 2 * qx1) / 2; 
        y = qx1 + qy1 - x;
        if(x >= 1 && y >= 1 && x <= N && y <= M && query(x, y) == 0) {
            std::cout << "! " << x << ' ' << y << std::endl;
            return;
        }
    }

    x = (2 * qx2 - d2) / 2; 
    y = qx2 + qy2 - x;
    std::cout << "! " << x << ' ' << y << std::endl;
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
