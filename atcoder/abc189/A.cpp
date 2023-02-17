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
    
    for(int i = 1; i < 3; i++) {
        if(S[i] != S[0]) {
            cout << "Lost" << '\n';
            return;
        }
    }

    cout << "Won" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
