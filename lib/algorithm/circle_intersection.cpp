#include <cmath>
#include <utility>
#include <vector>

// ABC157-F
std::vector<std::pair<double, double>> get_intersection(double x1, double y1, double r1, double x2, double y2, double r2) { 
    const double eps = 1e-9;

    std::vector<std::pair<double, double>> res;
    
    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if(r1 + r2 < d) {
        return res;
    }

    if(abs(d + r2 - r1) < eps) {
        double ratio = r1 / d;
        res.emplace_back((x2 - x1) * ratio + x1, (y2 - y1) * ratio + y1); 
    } else if(abs(d + r1 - r2) < eps) {
        double ratio = r2 / d;
        res.emplace_back((x1 - x2) * ratio + x2, (y1 - y2) * ratio + y2);
    } else if(abs(r1 + r2 - d) < eps) {
        double ratio = r1 / d;
        res.emplace_back((x2 - x1) * ratio + x1, (y2 - y1) * ratio + y1);
    } else {
        double r12 = r1 * r1;
        double r22 = r2 * r2;
        double d2 = d * d;
        double l = (r12 - r22 + d2) / (2.0 * d);
        double h = sqrt(r12 - l * l);
        for(int sign = -1; sign <= 1; sign += 2) {
            double x = l / d * (x2 - x1) + sign * h / d * (y2 - y1) + x1;
            double y = l / d * (y2 - y1) - sign * h / d * (x2 - x1) + y1;
            res.emplace_back(x, y);
        }
    }

    return res;
};
