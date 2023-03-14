#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    char C;
    cin >> C;

    if(C >= 'A' && C <= 'Z') {
        cout << 'A' << '\n';
    } else {
        cout << 'a' << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
