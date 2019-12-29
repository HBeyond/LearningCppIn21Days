#include <iostream>

using namespace std;

class Fish {
   public:
    void swim() { cout << "Fish swims" << endl; }

    void swim(bool FreshWaterFish) {
        if (FreshWaterFish) {
            std::cout << "swimming in lake" << std::endl;
        } else {
            std::cout << "swimming in sea" << std::endl;
        }
    }
};

class Tuna : public Fish {
   public:
    // using Fish::swim;  // method-2 to unhide, combine with the dinner.swim(false); in main()

    void swim() {
        cout << "Tuna can grow so big" << endl;
    }  // override the non-parameter method of base class, and hide the need-parameter one
    // when there are overload functions in base class, if one of them is overrode in the derived class, the other will
    // be hidden

    void swim(bool FreshWaterFish) {
        Fish::swim(FreshWaterFish);
    }  // method-3 to unhide. combine with the dinner.swim(false); in main()
};

int main() {
    Tuna dinner;
    dinner.swim();
    dinner.swim(false);  // if hide the need-parameter method of base class, that means all the methods are not turn on,
                         // this line will be wrong
    // dinner.Fish::swim(false);  // method-1 to unhide
}
// I think method-1 is the best one
