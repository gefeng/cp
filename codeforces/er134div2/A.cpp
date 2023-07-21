#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <vector>
#include <string>

using namespace std;

void run_case() {
    string S1, S2;
    cin >> S1 >> S2;

    array<int, 26> cnt{0};
    for(char c : S1) {
        cnt[c - 'a']++;
    }
    for(char c : S2) {
        cnt[c - 'a']++;
    }

    int tot = 0;
    for(int i = 0; i < 26; i++) {
        if(cnt[i]) {
            tot++;
        }
    }

    cout << max(0, tot - 1) << '\n';
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
