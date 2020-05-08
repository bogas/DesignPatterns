#include "common_design.h"
#include "testing.h"
using namespace std;

struct Square {
    int side{0};

    explicit Square(const int side) : side(side) {}
};

class MyRectangle {
public:
    virtual int width() const = 0;

    virtual int height() const = 0;

    int area() const { return width() * height(); }

    virtual ~MyRectangle() {
        cout << "\nDestructing MyRectangle\n";
    }
};

struct SquareToRectangleAdapter : MyRectangle {
    SquareToRectangleAdapter(const Square &square) : side(square.side) {
    }

    int width() const override {
        return side;
    }

    int height() const override {
        return side;
    }
    int area() const { cout<<"Derived area\n"; return 0; }

private:
    int side;
};

TEST_CASE("", "") {
    Square sq{13};
    unique_ptr<MyRectangle> adapter = make_unique<SquareToRectangleAdapter>(sq);
    REQUIRE(adapter->area() == 169);
}



