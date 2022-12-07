#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string S;
    cin >> S;

    array<int, 26> cnt{0};
    for(char c : S) {
        cnt[c - 'a'] += 1;
    }
    
    int x = 0;
    for(int i = 0; i < 26; i++) {
        if(cnt[i]) {
            x += 1;
        }
    }

    if(x == 1) {
        cout << 1 << '\n';
    } else if(x == 2) {
        cout << 3 << '\n';
    } else {
        cout << 6 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
