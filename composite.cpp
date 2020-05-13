#include "composite.h"

int sum(const vector<ContainsIntegers *> items) {
    return accumulate(begin(items), end(items), 0, [](const int& sum, const auto& element) { return sum + element->sum(); });
}

int main() {
    SingleValue sv{10};
    ManyValues mv;
    mv.add(3).add(4);
    cout << "\nSum: " << sum({&sv, &mv}) << endl;
    return 0;
}