#include <iostream>

using namespace std;

class shape {
   public:
    virtual double area() = 0;
    virtual void print() = 0;
};

class circle : public shape {
   public:
    circle(double rPass) : r(rPass) {}
    double area() { a = r * r * 3.14; }

    void print() { cout << "the area of this circle is: " << a << endl; }

   private:
    double r = 0.0;
    double a = 0.0;
};

class triangle : public shape {
   public:
    triangle(double underWidthPass, double heightPass) : underWidth(underWidthPass), height(heightPass) {}
    double area() { a = underWidth * height / 2; }
    void print() { cout << "the area of this triangle is: " << a << endl; }

   private:
    double underWidth = 0.0;
    double height = 0.0;
    double a = 0.0;
};

int main() {
    circle k(2.0);
    triangle t(3.0, 4.0);
    k.area();
    k.print();
    t.area();
    t.print();
}
