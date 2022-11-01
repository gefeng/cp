#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int K;
    cin >> K;

    int min = 21 * 60 + K;
    int h = min / 60;
    int m = min % 60;
    
    cout << to_string(h) + ":" + (m < 10 ? "0" + to_string(m) : to_string(m)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
