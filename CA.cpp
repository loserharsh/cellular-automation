#include <iostream>
#include <vector>
#include <array>

int apply_rule(int left, int center, int right) {
    if (left == 1 && center == 0 && right == 0) return 1;
    if (left == 0 && center == 1 && right == 1) return 1;
    if (left == 0 && center == 1 && right == 0) return 1;
    if (left == 0 && center == 0 && right == 1) return 1;
    return 0;
}

int main(){
    int width = 61;
    int generation =10q;

    std::vector<int> current(width,0);
    current[width/2 ] = 1;

    for (int gen = 0; gen < generation; gen++) {

        for (int i = 0; i < width; i++) {
            if (current[i] == 1) {
                std::cout << '#';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';

        std::vector<int> next(width, 0);
        for (int i = 0; i < width; i++) {
            int left   = (i > 0) ? current[i - 1] : 0;
            int center = current[i];
            int right  = (i < width - 1) ? current[i + 1] : 0;

            next[i] = apply_rule(left, center, right);
        }

        current = next;
    }

    return 0;
}