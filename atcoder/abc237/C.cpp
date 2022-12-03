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

    bool is_pal = true;
    for(int l = 0, r = S.length() - 1; l < r; l++, r--) {
        if(S[l] != S[r]) {
            is_pal = false;
            break;
        }
    }

    if(is_pal) {
        cout << "Yes" << '\n';
        return;
    }

    int st = 0;
    int ed = S.length() - 1;
    while(st < S.length() && S[st] == 'a') {
        st += 1;
    }

    while(ed >= 0 && S[ed] == 'a') {
        ed -= 1;
    }

    is_pal = true;
    for(int l = st, r = ed; l < r; l++, r--) {
        if(S[l] != S[r]) {
            is_pal = false;
            break;
        }
    }

    cout << (is_pal && st + 1 <= S.length() - ed - 1 ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
