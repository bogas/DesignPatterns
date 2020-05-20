#include <ostream>
#include <iostream>
struct Point
{
    int x{ 0 }, y{ 0 };

    Point(){}

    Point(const int x, const int y) : x{x}, y{y} {}

    friend std::ostream &operator<<(std::ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};

struct Line
{
    Point *start, *end;

    Line(Point* const start, Point* const end)
            : start(start), end(end)
    {
    }

    ~Line()
    {
        delete start;
        delete end;
    }

    Line deep_copy() const
    {
        Line result{new Point(*this->start), new Point(*this->end)};
        return result;
        // TODO
    }

    friend std::ostream &operator<<(std::ostream &os, const Line &line) {
        os << "start: " << *line.start << " end: " << *line.end;
        return os;
    }
};

int main () {
    Line l{new Point(0,1), new Point(2,2)};
    auto l2= l.deep_copy();
    l.end->x = 19;
    std::cout<<l << std::endl <<l2<<std::endl;

}