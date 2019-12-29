#include <iostream>

using namespace std;

class Motor {
   public:
    void switchingIgnition() { cout << "ignition on" << endl; }

    void pumpFuel() { cout << "pumping fuel" << endl; }

    void fireCylinder() { cout << "fire cylinder" << endl; }
};

class Car : private Motor {
   public:
    void Move() {
        switchingIgnition();
        pumpFuel();
        fireCylinder();
    }
};

class Ferreri : public Car {
   public:
    // void superMove() {
    // switchingIgnition();  // these method in Motor cannot be accessible besides its private inherit
    // pumpFuel();
    // fireCylinder();
    //}
};

int main() {
    Car myLittleLion;
    myLittleLion.Move();
    // myLittleLion.Motor::fireCylinder();  //no matter how to try to get the method of Motor beyond the definition of
    // Car, you can not.

    Ferreri laFa;
    laFa.Move();  // but it can call the method of Car, and through the method of Car to call the method in Motor, but
                  // can not modify
}
