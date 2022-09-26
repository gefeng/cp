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

    int n = S.length();
    string ans = "";
     
    array<int, 10> cnt{0};
    int min_d = 10;
    for(int i = n - 1; i >= 0; i--) {
        int c = S[i] - '0';
        min_d = min(min_d, c);

        if(c == min_d) {
            cnt[c]++;
        } else {
            cnt[min(9, c + 1)]++;
        }
    }

    for(int i = 0; i < 10; i++) {
        while(cnt[i]) {
            ans.push_back((char)(i + '0'));
            cnt[i]--;
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
