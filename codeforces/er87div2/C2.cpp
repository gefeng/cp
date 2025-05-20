#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

const double PI = std::acos(-1);

void run_case() {
    int N;
    std::cin >> N;
    
    double theta = PI / N;
    
    double ans = std::cos(theta / 4.0) / std::sin(theta / 2.0);
    
    std::cout << std::setprecision(20) << ans << '\n';
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
