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

    if(N > 0 && N < 126) {
        cout << 4 << '\n';
    } else if(N > 125 && N < 212) {
        cout << 6 << '\n';
    } else {
        cout << 8 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
