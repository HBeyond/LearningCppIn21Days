#include <iostream>

using namespace std;

class animal {
   public:
    animal() { cout << "animal construct" << endl; }
    int age;
};

class mamal : public virtual animal {};

class bird : public virtual animal {};

class reptile : public virtual animal {};

class platpus : public mamal, public bird, public reptile {
   public:
    platpus() { cout << "platpus construct" << endl; }
};

int main() {
    platpus duckBilledP;  // 1. if not virtual inherit, this line will call the base constructor 3 times, because class
                          // platpus derive from three classes which all derive from base class
    duckBilledP.age = 3;  // 2. if not virtual inherit, this line will go wrong, because there has 3 animal in memory,
                          // so 3 age as well, compiler doesn`t know which do you want to use
}
