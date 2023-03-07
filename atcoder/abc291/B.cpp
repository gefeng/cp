#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void run_case() {
    int n;
    cin >> n;

    vector<int> a(5 * n);
    for(int i = 0; i < 5 * n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    int sum = 0;
    for(int i = n; i < 4 * n; i++) {
        sum += a[i];
    }

    cout << setprecision(20) << (double)sum / (3 * n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
