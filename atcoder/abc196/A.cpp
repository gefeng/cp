#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int ans = -500;
    for(int x = A; x <= B; x++) {
        for(int y = C; y <= D; y++) {
            ans = max(ans, x - y); 
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
