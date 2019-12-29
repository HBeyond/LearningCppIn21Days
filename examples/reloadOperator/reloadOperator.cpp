#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Element {
   public:
    Element() = default;
    Element(const int& a, const double& b) : a_(a), b_(b) {}
    Element(const Element&) = default;

    Element operator+(const Element& addThis) {
        Element result;
        result.a_ = this->a_ + addThis.a_;
        result.b_ = this->b_ + addThis.b_;
        return result;
    }
    Element& operator=(const Element& equal) {
        this->b_ = equal.b_;
        return *this;
    }

    int getA() { return a_; }
    double getB() { return b_; }

   private:
    int a_;
    double b_;
};

int main(int argc, char* argv[]) {
    Element X(2, 2.0);

    Element Y(1, 1.0);

    Element Z;
    Z = Y = X;

    cout << Z.getA() << ", " << Z.getB() << endl;

    return 0;
}
