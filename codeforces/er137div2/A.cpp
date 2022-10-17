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

    array<bool, 10> is_not{false};
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;
        is_not[X] = true;
    }

    int ans = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = i + 1; j < 10; j++) {
            if(!is_not[i] && !is_not[j]) {
                ans += 6;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
