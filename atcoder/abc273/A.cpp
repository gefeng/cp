#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int f(int x) {
    if(x == 0) {
        return 1;
    }
    return x * f(x - 1);
}
void run_case() {
    int N;
    cin >> N;
    
    cout << f(N) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
