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

    int n = 0;
    for(int i = 1; i <= N; i *= 2) {
        n += 1;
    }

    auto query = [](std::string&& t, int x, int y) {
        std::cout << t << ' ' << x + 1 << ' ' << y + 1 << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    int a = query("XOR", 0, 2); 
    int b = query("XOR", 1, 2); 
    int c = query("AND", 0, 1);
    int d = query("AND", 1, 2);
    int e = query("AND", 0, 2);

    int x = 0;
    int y = 0;
    int z = 0;
    for(int i = 0; i < n; i++) {
        int b_1 = (a & (1 << i)) ? 1 : 0;
        int b_2 = (b & (1 << i)) ? 1 : 0;
        
        if(b_1 == 0 && b_2 == 0) {
            if(c & (1 << i)) {
                x |= 1 << i;
                y |= 1 << i;
                z |= 1 << i;
            } 
        } else if(b_1 == 1 && b_2 == 1) {
            if(c & (1 << i)) {
                x |= 1 << i;
                y |= 1 << i;
            } else {
                z |= 1 << i;
            }
        } else if(b_1 == 1 && b_2 == 0) {
            if(d & (1 << i)) {
                y |= 1 << i;
                z |= 1 << i;
            } else {
                x |= 1 << i;
            }
        } else if(b_1 == 0 && b_2 == 1) {
            if(e & (1 << i)) {
                x |= 1 << i;
                z |= 1 << i;
            } else {
                y |= 1 << i;
            }
        }
    }

    std::vector<int> ans(N, 0);
    ans[0] = x;
    ans[1] = y;
    ans[2] = z;

    for(int i = 3; i < N; i++) {
        int res = query("XOR", 0, i);
        ans[i] = res ^ ans[0];
    }

    std::cout << "! ";
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
