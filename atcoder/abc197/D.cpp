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
    int N;
    cin >> N;
    
    int X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;

    double x = ((double)X1 - X2) / 2.0;
    double y = ((double)Y1 - Y2) / 2.0;
    double theta = (2.0 * acos(-1.0)) / N;

    double ans_x = cos(theta) * x - sin(theta) * y;
    double ans_y = sin(theta) * x + cos(theta) * y;

    cout << setprecision(20) << ans_x + ((double)X1 + X2) / 2.0 << ' ' << ans_y + ((double)Y1 + Y2) / 2.0 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
