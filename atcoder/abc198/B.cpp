#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

bool is_pal(string& s, int l, int r) {
    while(l < r) {
        if(s[l] != s[r]) {
            return false;
        }
        l += 1;
        r -= 1;
    }
    return true;
}

void run_case() {
    int N;
    cin >> N;
    
    string s = to_string(N);

    if(is_pal(s, 0, s.size() - 1)) {
        cout << "Yes" << '\n';
        return;
    }

    int r = s.size() - 1;
    while(r >= 0 && s[r] == '0') {
        r -= 1;
    }

    if(is_pal(s, 0, r)) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
