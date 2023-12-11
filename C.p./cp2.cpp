#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <memory>
using namespace std;
const float PI = 3.14;
class Figure
{
public:
    virtual string Name() const = 0;
    virtual float Perimeter() const = 0;
    virtual float Area() const = 0;
    //^--- віртуальні методи
    virtual ~Figure() = default;
    //^--- віртуальний деструктор
};
class Triangle : public Figure
{
public:
    Triangle(int a, int b, int c) : a_(a), b_(b), c_(c) {}

    string Name() const override
    {
        return "TRIANGLE";
    }

    float Perimeter() const override
    {
        return a_ + b_ + c_;
    }

    float Area() const override
    {
        float s = Perimeter() / 2.0;
        return sqrt(s * (s - a_) * (s - b_) * (s - c_));
    }

private:
    int a_;
    int b_;
    int c_;
};
class Rect : public Figure
{
public:
    Rect(int width, int height) : width_(width), height_(height) {}

    string Name() const override
    {
        return "RECT";
    }

    float Perimeter() const override
    {
        return 2 * (width_ + height_);
    }

    float Area() const override
    {
        return width_ * height_;
    }

private:
    int width_;
    int height_;
};
class Circle : public Figure
{
public:
    Circle(int r) : radius_(r) {}

    string Name() const override
    {
        return "CIRCLE";
    }

    float Perimeter() const override
    {
        return 2 * PI * radius_;
    }

    float Area() const override
    {
        return PI * radius_ * radius_;
    }

private:
    int radius_;
};
shared_ptr<Figure> CreateFigure(istream &is)
{
    string type;
    is >> type;

    if (type == "RECT")
    {
        float width, height;
        is >> width >> height;
        return make_shared<Rect>(width, height);
    }
    else if (type == "TRIANGLE")
    {
        float a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }
    else if (type == "CIRCLE")
    {
        float radius;
        is >> radius;
        return make_shared<Circle>(radius);
    }

    // В разі невідомого типу повертаємо nullptr.
    return nullptr;
}
int main()
{
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line);)
    {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD")
        {
            is >> ws;
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT")
        {
            for (const auto &current_figure : figures)
            {
                cout << fixed << setprecision(3) << current_figure->Name() << " " << current_figure->Perimeter() << " " << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}