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

    int ans = 1.08 * N;

    if(ans < 206) {
        cout << "Yay!" << '\n';
    } else if(ans == 206) {
        cout << "so-so" << '\n';
    } else {
        cout << ":(" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
