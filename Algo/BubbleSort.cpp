#include "../common_design.h"

[[nodiscard]] vector<int> buildData(int size) {
    vector<int> result(size);
    srand(time(nullptr));
    generate(begin(result), end(result), rand);
    return result;
}

template<typename T>
void print(vector<T> vv) {
    cout << "----------------------------------------" << endl;
    for (auto &v: vv)
        cout << v << " ";
    cout << "\n----------------------------------------" << endl;
}

void bubble(vector<int>& input) {
    for (auto i = 0; i < input.size(); i++) {
        for (auto j = i + 1; j < input.size(); j++) {
            if (input[i] > input[j])
                swap(input[i], input[j]);
        }
    }
}

int main() {
    auto v = buildData(30);
    print(v);
    bubble(v);
    print(v);

    return 0;

}

