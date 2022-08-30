#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <vector>
#include <string>

using namespace std;

void run_case() {
    int N;
    string S;
    string T = "Timur";

    cin >> N >> S;

    array<int, 52> cnt1 = {0};
    array<int, 52> cnt2 = {0};

    for(char c : T) {
        if(c >= 'a' && c <= 'z') {
            cnt1[c - 'a']++;
        } else {
            cnt1[c - 'A' + 26]++;
        }
    }

    for(char c : S) {
        if(c >= 'a' && c <= 'z') {
            cnt2[c - 'a']++;
        } else {
            cnt2[c - 'A' + 26]++;
        }
    }

    bool ans = true;
    for(int i = 0; i < 52; i++) {
        if(cnt1[i] - cnt2[i] != 0) {
            ans = false;
            break;
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';
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
