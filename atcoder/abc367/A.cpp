#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, C;
    std::cin >> A >> B >> C;
    
    if(B == C) {
        std::cout << "No" << '\n';
        return;
    }
#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, C;
    std::cin >> A >> B >> C;
    
    if(B == C) {
        std::cout << "No" << '\n';
        return;
    }

    if(B < C) {
        std::cout << (A >= B && A < C ? "No" : "Yes") << '\n';
        return;
    }
    
    std::cout << (((A >= 0 && A < C) || A >= B) ? "No" : "Yes") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}

    if(B < C) {
        std::cout << (A >= B && A < C ? "No" : "Yes") << '\n';
        return;
    }
    
    std::cout << (((A >= 0 && A < C) || A >= B) ? "No" : "Yes") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
