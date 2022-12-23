#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int S, T;
    cin >> S >> T;

    int ans = 0;
    for(int a = 0; a <= S; a++) {
        for(int b = 0; b <= S; b++) {
            for(int c = 0; c <= S; c++) {
                if(a + b + c <= S && a * b * c <= T) {
                    ans += 1;
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
