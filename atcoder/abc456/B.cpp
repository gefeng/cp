#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

void run_case() {
    std::vector<std::vector<int>> A(3, std::vector<int>(6, 0));

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 6; j++) {
            std::cin >> A[i][j];
        }
    }

    double ans = 0.0;
    std::array<int, 3> t{4, 5, 6};    
    std::array<int, 3> a{0, 1, 2};

    do {
        double p = 1.0;
        for(int i = 0; i < 3; i++) {
            int j = a[i];
            int c = 0;
            for(int x : A[j]) {
                if(x == t[i]) {
                    c++;
                }
            }
            p *= c / 6.0;
        }
        ans += p;
    } while(std::next_permutation(a.begin(), a.end()));

    std::cout << std::setprecision(20) << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
