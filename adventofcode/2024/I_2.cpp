#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

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
    std::map<int, int> space;
    for(int i = 0; i < n; ) {
        int j = i;
        while(i < n && a[i] == a[j]) {
            i += 1;
        }
        if(a[j] == -1) {
            space[j] = i - 1;
        }
    }
    
    for(int i = n - 1; i >= 0; ) {
        int j = i;
        while(i >= 0 && a[i] == a[j]) {
            i -= 1;
        }
        
        if(a[j] == -1) {
            continue; 
        }

        int len = j - i;
        
        for(auto [l, r] : space) {
            if(r - l + 1 >= len && l <= i) {
                int v = a[j];
                for(int k = 0; k < len; k++) {
                    a[l + k] = v;
                    a[j - k] = -1;
                } 
                space.erase(l);
                if(r - l + 1 > len) {
                    space.emplace(l + len, r); 
                }
                break;
            }
        }
    }

    // for(int i = 0; i < n; i++) {
    //     std::cout << a[i] << " \n"[i == n - 1];
    // }

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
