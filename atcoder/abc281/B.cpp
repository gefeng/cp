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

    bool ans = true;
    int n = S.length();
    if(n != 8) {
        ans = false;
    } else {
        if(S[0] < 'A' || S[0] > 'Z') {
            ans = false;
        } else if(S[n - 1] < 'A' || S[n - 1] > 'Z') {
            ans = false;
        } else {
            if(S[1] == '0') {
                ans = false;
            }

            for(int i = 1; i < 7; i++) {
                if(S[i] < '0' || S[i] > '9') {
                    ans = false;
                    break;
                }
            } 
        }
    }

    cout << (ans ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
