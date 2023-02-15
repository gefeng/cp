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

    int N = S.size();

    bool ans = true;
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            if(S[i] < 'a' || S[i] > 'z') {
                ans = false;
                break;
            }
        } else {
            if(S[i] < 'A' || S[i] > 'Z') {
                ans = false;
                break;
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
