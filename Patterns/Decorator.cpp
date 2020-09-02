#include "../common_design.h"
using namespace std;

struct Flower
{
    virtual string str() = 0;
};

struct Rose : Flower
{
    string name = "A rose";
    string str() override {
        string result;
        result += name;
        return result;
    }

};

static void add_attribute(string& str, string attr)
{
    if(str.find(attr) != string::npos)
        return;
    if(str.find("that") == string::npos)
    {
        str+= " that is " + attr;
    } else{
        str+= " and " + attr;
    }
}
struct RedFlower : Flower
{
    RedFlower( Flower& flower) : flower(flower) {}
    string str() override {
        string result = flower.str();
        add_attribute(result,"red");
        return result;
    }
    Flower& flower;
};

struct BlueFlower : Flower
{
    BlueFlower( Flower& flower) : flower(flower) {}
    string str() override {
        string result = flower.str();
        add_attribute(result,"blue");
        return result;
    }
    Flower& flower;
};


int main()
{
    Rose rose;
    RedFlower red_rose{rose};
    RedFlower red_red_rose{red_rose};
    BlueFlower red_blue_rose{red_rose};
    BlueFlower blue_rose{rose};

    cout << rose.str() <<endl;
    cout << red_rose.str() << endl;
    cout << red_red_rose.str()<<endl;
    cout << red_blue_rose.str()<<endl;
    cout << blue_rose.str()<<endl;
    return 0;

}