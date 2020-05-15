#include "../common_design.h"

struct S{
    char x;
    char *y;
    static int  z;
};
int S::z = 1;

struct Y{
    short a;
    int c;
    short b;
};

int main()
{
    cout<< sizeof(S)<<endl;
    vector<int> a{1,2,7,3,4,5,6,3,1,2,3};
    sort(begin(a), end(a));
    auto last = unique(begin(a), end(a));
    a.erase(last, end(a));
//    for(auto aa: a)
//        cout<<aa<<" ";

    unordered_set<int> b;
    vector<int> v{1,2,7,3,4,5,6,3,1,2,3};
    for(auto aa: v)
        b.insert(end(b),aa);
    for(auto aa: b)
        cout<<aa<<" ";

    int t[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<sizeof(t)<<endl;
    int* p = t;
    auto first = t;
    for(auto a=0;a<10;++a)
    {
        cout<<*p++<<" " << p<<" "<<p-first<<endl;

    }


}