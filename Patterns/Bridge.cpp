#include "../common_design.h"

using namespace std;


struct Renderer {
    virtual string what_to_render_as() const = 0;
};

struct Shape {
private:
    Renderer &renderer;
protected:
    string name;

public:
    string str() { return "Drawing " + name + renderer.what_to_render_as(); }
    Shape(Renderer &renderer) : renderer(renderer) {}
};

struct Triangle : Shape {
    Triangle(Renderer &renderer) : Shape(renderer) {
        name = "Circle";
    }
};

struct Square : Shape {
    Square(Renderer &renderer) : Shape(renderer)
    {
        name = "Square";
    }
};


struct VectorRenderer : Renderer {
    string what_to_render_as() const {
        return " as lines";
    }
};

struct RasterRenderer : Renderer {
    string what_to_render_as() const {
        return " as pixels";
    }
};

int main()
{
    RasterRenderer rr;
    VectorRenderer vr;
    Triangle triangle(rr);
    Square sq (vr);
    cout<< triangle.str() << " " << sq.str() <<endl;
    return 0;
}

