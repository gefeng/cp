#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string S, T;
    cin >> S >> T;

    if(S.length() != T.length()) {
        cout << "No" << '\n';
        return;
    }

    int n = S.length();
    int cnt = 0;
    for(int i = 0; i < n - 1; i++) {
        if(S[i] != T[i]) {
            if(cnt || (S[i] != T[i + 1] || S[i + 1] != T[i])) {
                cout << "No" << '\n';
                return;
            } 
            swap(S[i], S[i + 1]);
            cnt += 1;
        }
    }

    if(S[n - 1] != T[n - 1]) {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
