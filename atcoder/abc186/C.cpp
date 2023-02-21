#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    auto has_seven = [](int x, int base) {
        while(x) {
            if(x % base == 7) {
                return true;
            }
            x /= base;
        }
        return false;
    };

    int ans = N;
    for(int i = 1; i <= N; i++) {
        if(has_seven(i, 10) || has_seven(i, 8)) {
            ans -= 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
