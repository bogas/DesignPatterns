#include "../common_design.h"

int main()
{
    vector<int> v{1,2,3,4,5,1,2,4,3,77};
    cout <<accumulate(begin(v), end(v), 0)<<endl;
    cout <<reduce(begin(v), end(v), 0)<<endl;
    for(auto& vv: v) cout<<vv<<" ";
}

