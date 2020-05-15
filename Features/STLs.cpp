#include "../common_design.h"
#include <optional>
#include <any>

int main()
{
    vector<int> v{1,2,3,4,5,1,2,4,3,77};
    cout <<accumulate(begin(v), end(v), 0)<<endl;
    cout <<reduce(begin(v), end(v), 0)<<endl;
    for(auto& vv: v) cout<<vv<<" ";
    optional<string> a = "dada";
    optional<string> b;
    cout<<a.value_or("Pusty ") << b.value_or("Pusty")<<endl;
    std::any aa = 1;
    auto aaI = any_cast<int>(aa);
    aa = 1.2f;
    auto aaF = any_cast<float>(aa);
    cout<<aaI <<" "<<aaF<<endl;
}

