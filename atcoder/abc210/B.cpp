#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    int lose = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            break;
        }
        lose ^= 1;
    }

    cout << (lose == 0 ? "Takahashi" : "Aoki") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
