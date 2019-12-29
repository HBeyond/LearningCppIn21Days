#include <iostream>

class Fish {
   public:
    virtual void swim() = 0;
    // virtual void test() { std::cout << "must be overrode?" << std::endl; }  //answer is: no!!
    // virtual ~Fish() { std::cout << "destroy Fish" << std::endl; }
    virtual ~Fish(){};
};

class Tuna : public Fish {
   public:
    void swim() { std::cout << "Tuna swim in sea" << std::endl; }
    //~Tuna() { std::cout << "destroy Tuna" << std::endl; }
    ~Tuna(){};
};

class Carp : public Fish {
   public:
    void swim() {
        std::cout << "Tuna swim in lake" << std::endl;
    }  // the derived class must override the pure virtual method in abstract base class
    void taste() { std::cout << "carp tastes not bad" << std::endl; }
    //~Carp() { std::cout << "destroy Carp" << std::endl; }
    ~Carp(){};
};

int main() {
    // Fish fish();
    // fish.swim();
    Tuna lunch;
    lunch.swim();
    Carp dinner;
    // dinner.swim();
    dinner.taste();
}
