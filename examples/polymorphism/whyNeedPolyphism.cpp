#include <iostream>

using namespace std;

class Fish {
   public:
    virtual void swim() { cout << "Fish swim" << endl; }
};

class Tuna : public Fish {
   public:
    void swim() { cout << "Tuna swim" << endl; }
};

void makeFishSwim(Fish& inputFish) { inputFish.swim(); }

int main() {
    Tuna myDinner;
    myDinner.swim();
    makeFishSwim(myDinner);  // if the polymorphism technology is not used, the output of this line is Fish swim. That
                             // means, when a derived class example is passed as a formal parameter to a function, where
                             // a override function is called. But it calls the function in base class but not derived
                             // class
    // if want the last line to cout the function of derived class, the overrode function in base class must be
    // embellished by virtual.
    // in C++, polymorphism is virtual
}
