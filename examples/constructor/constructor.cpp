#include <iostream>

using namespace std;

class Fish {
    // if use public, then this variance can be changed beyond the base class and derived class. but we don`t
    // want it to happen, because some confusion will come up as Tunua Dinner; Dinner.FreshWaterFish = true; then tuna
    // can swim in the lake. it is wrong
    // public:
   protected:
    bool FreshwaterFish;

   public:
    // Fish constructor
    Fish(bool isFreshWaterFish) : FreshwaterFish(isFreshWaterFish) {}

    void swim() {
        if (FreshwaterFish) {
            std::cout << "swimming in lake" << std::endl;
        } else {
            std::cout << "swimming in sea" << std::endl;
        }
    }
};

class Tuna : public Fish {
   public:
    // Tuna() { FreshwaterFish = false; }  //constructor1 of derived class, the normal one
    Tuna() : Fish(false) {}  // constructor2 of derived class, call the constructor of base class and pass parameters
                             // this method can remind the derived class of giving a initial value
    void swim() {
        cout << "Tuna can grow so big" << endl;  // override(fugai, chongxie) the base class method
        Fish::swim();  // call the base method in the overrode method in derived class with scope resolution operator ::
    }
};

class Carp : public Fish {
   public:
    // Carp() { FreshwaterFish = true; }
    Carp() : Fish(true) {}

    void swim() {
        cout << "Carp can not grow too big" << endl;
        Fish::swim();
    }
};

int main() {
    Tuna Lunch;
    Carp Dinner;

    cout << "My lunch: ";
    Lunch.swim();  // call the override method of derived class
    cout << "My lunch: ";
    Lunch.Fish::swim();  // call the override method of base class
    cout << "My dinner: ";
    Dinner.swim();
    //    Dinner.FreshwaterFish = false; //when FreshWaterFish is protected, the following 3 lines will be wrong
    //    cout << "My dinner can ";
    //    Dinner.swim();

    return 0;
}
