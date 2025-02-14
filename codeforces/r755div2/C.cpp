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

    std::vector<int> freq_a(300, 0);
    std::vector<int> freq_b(300, 0);
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        freq_a[X + 100] += 1;
    }

    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        freq_b[X + 100] += 1;
    }

    int carry = 0;
    for(int i = 0; i <= 200; i++) {
        if(freq_a[i] + carry == freq_b[i]) {
            carry = 0;
            continue; 
        }
        if(freq_a[i] + carry < freq_b[i] || carry > freq_b[i]) {
            std::cout << "NO" << '\n';
            return;
        }

        freq_b[i] -= carry;
        carry = freq_a[i] - freq_b[i];
    } 

    std::cout << (carry == 0 ? "YES" : "NO") << '\n';
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
