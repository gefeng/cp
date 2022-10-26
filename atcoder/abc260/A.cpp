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
    for(int i = 0; i < 3; i++) {
        bool unique = true;
        for(int j = 0; j < 3; j++) {
            if(i != j && S[i] == S[j]) {
                unique = false;
            }
        }

        if(unique) {
            cout << S[i] << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
