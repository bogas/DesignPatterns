#include "../common_design.h"

int main()
{
    string sentence = "  Ala ma  kokota";
    string_view view = sentence;
    auto pos = view.find_first_not_of(" ");
    view.remove_prefix(pos);
    cout<<view<<endl;
}
