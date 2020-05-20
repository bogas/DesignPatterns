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
vector<int> insertSort(vector<int>& input)
{
    list<int> result;
    for(auto i = 0; i< input.size(); i++)
    {
        auto insertPlace = begin(result);
        for(auto& it = insertPlace; it != result.end(); it++)
        {
            auto next = it;
            next++;
            if( *it < *next)
                break;
        }

    }
}

