#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    std::string S;
    std::cin >> S;

    std::array<int, 10> cnt = {};
    for(int i = 0; i < 4; i++) {
        cnt[S[i] - '0'] += 1;
    }

    for(int i = 0; i < 10; i++) {
        if(cnt[i] == 4) {
            cout << -1 << '\n';
            return;
        }

        if(cnt[i] == 3) {
            cout << 6 << '\n';
            return;
        }
    }

    cout << 4 << '\n';
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
