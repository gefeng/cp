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
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    double pi = acos(-1);
    double a = (((double)H * 60 + M) / (12 * 60)) * 2 * pi; 
    double b = ((double)M / 60) * 2 * pi;
    double theta = abs(a - b);
    if(theta > pi) {
        theta = 2 * pi - theta;
    }

    double x = sin(theta) * A * sin(theta) * A;
    double y = (B - cos(theta) * A) * (B - cos(theta) * A);

    cout << setprecision(20) << sqrt(x + y) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
