#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    char P, Q;
    std::cin >> P >> Q;

    if(P > Q) {
        std::swap(P, Q);
    } 

    std::vector<int> dist = {0, 3, 1, 4, 1, 5, 9};
    
    int ans = 0;
    for(int i = P - 'A' + 1; i <= Q - 'A'; i++) {
        ans += dist[i];
    } 

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
