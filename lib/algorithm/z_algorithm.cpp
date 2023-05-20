#include <vector>
#include <string>

std::vector<int> z_algorithm(std::string& s) {
    int n = s.length();
    std::vector<int> z(n, 0);

    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        z[i] = std::max(0, std::min(z[i - l], r - i + 1));
        while(i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            l = i;
            r = i + z[i];
            z[i] += 1;
        }
    } 

    return z;
}
