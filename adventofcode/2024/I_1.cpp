#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;
    
    int n = S.size();
    
    std::vector<int> a; 
    int id = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < S[i] - '0'; j++) {
                a.push_back(id);
            }
            id++;
        } else {
            for(int j = 0; j < S[i] - '0'; j++) {
                a.push_back(-1);
            }
        }
    }

    n = a.size();
    for(int l = 0, r = n - 1; l <= r; ) {
        while(l <= r && a[l] != -1) {
            l += 1;
        }

        while(l <= r && a[r] == -1) {
            r -= 1;
        }

        if(l <= r) {
            std::swap(a[l], a[r]);
        }
    }

    int64_t checksum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != -1) {
            checksum += i * a[i];
        }
    }

    std::cout << checksum << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
