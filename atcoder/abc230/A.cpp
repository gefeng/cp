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

    string ans = "AGC0";
    if(N < 42) {
         if(N < 10) {
             cout << ans + "0" + to_string(N) << '\n';
         } else {
             cout << ans + to_string(N) << '\n';
         }
    } else {
        cout << ans + to_string(N + 1) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
