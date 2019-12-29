#include <gflags/gflags.h>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <chrono>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "sophus/so3.hpp"

using namespace std;
using namespace chrono;

// int x_global = 5;
// int y_global = 6;

// void f(int& n1, int& n2, const int& n3) {
//    std::cout << "In function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
//    ++n1;  // increments the copy of n1 stored in the function object
//    ++n2;  // increments the main()'s n2
//    //++n3;  // compile error
//}

// void sum(int a, int b) {
//    a = 8;
//    b = 9;
//    int c = a + b;
//}

// enum workDay { Mon, Tue, Wens, Thur, Fri };

// std::string rootFolder = "/home/beyoung/work/TestCache/testCache";

// double volume(double& radius, double pi = 3.14) { return (4 * pi * radius * radius * radius) / 3; }

// double volume(double& radius, double& pi, double& height) { return pi * radius * radius * height; }

///**
// * @brief The class
// */
// class Human {
//   public:
// /*constructor1: default constructor*/
// Human() {}
/* 1. constructor2: constructor with default parameters is regarded as default constructor too, and constructor2
would better to avoid existing with constructor1 at the same time, because if input without any info, the
compiler dose not know which constructor to call. And in this cosntructor, the assignment must be given in the
code block, or you cannot assign value to the private variance*/
/* 2. but in this kind, you can not give a new value to the second variance(here is age), without assigning a new
value to the first one(here is name), because both of them have a default value, and you can use "Human def;" or
"Human A("A"), or even "Human B("B", 20)" to call the constructor to construct a new object, but can not use it
as "Human C( , 20);", because the compiler dose not realize it*/
//    Human(string name = "Adam", int age = 20) : humanName_(name), humanAge_(age) {
//        //        humanName_ = name;
//        //        humanAge_ = age;
//        cout << "the Human class " << humanName_ << " has been constructed with constructor 2, and the age is "
//             << humanAge_ << endl;
//    }
/* constructor3 : normal constructor with assignment the variance in the code block, , and you can choose only one
assignment method between constructor1, 3 and 4.*/
//    Human(string name, int age) {
//        humanName_ = name;
//        humanAge_ = age;
//        cout << "the Human class " << humanName_ << " has been constructed with constructor4, and the age is "
//             << humanAge_ << endl;
//    }
/*constructor5: copy constructor, after define this, the object of this class can be passed to some sub-function
 * as
 * a quote*/
//    Human(const Human& copySource) { cout << "the class Human has been copied!" << endl; }

//    void setName(string name) {
//        if (typeid(name) == typeid(string)) {
//            humanName_ = name;
//        }
//        cout << "the input is not a valid name in string!" << endl;
//    }

//    string getName() { return humanName_; }

//    void setAge(int age) {
//        if (typeid(int) != typeid(int)) {
//            cout << "the input is not a valid age in int!" << endl;
//        } else if (age > 50) {
//            humanAge_ = age - 10;
//        } else {
//            humanAge_ = age;
//        }
//    }

//    int getAge() { return humanAge_; }

//    ~Human() {
//        cout << "destructor!" << endl;
//        // delete[] Human;
//    }

//   private:
//    string humanName_;
//    int humanAge_;
//};

// void isAdult(Human& person) {  // the formal parameter list must be the same as the copy constructor
//    cout << "the age of " << person.getName() << " is " << person.getAge() << endl;
//    if (person.getAge() > 18) {
//        cout << person.getName() << " is an adult!" << endl;
//    } else {
//        cout << person.getName() << " is not an adult!" << endl;
//    }
//}

class Fish {
   public:
    //  **  generally situation
    //    Fish() { cout << "a fish is coming!" << endl; }

    //    void swim() {
    //        if (freshWater == true) {
    //            cout << "swim in lake" << endl;
    //        } else {
    //            cout << "swim in sea" << endl;
    //        }
    //    }

    Fish(bool freshWater) {
        if (freshWater == true) {
            cout << "swim in lake" << endl;
        } else {
            cout << "swim in sea" << endl;
        }
    }

   protected:
    bool freshWater = true;
};

class crucian : public Fish {
   public:
    //  ** generally situation
    //    crucian() {
    //        freshWater = true;
    //        cout << "a crucian is coming!" << endl;
    //    }

    //    bool eatMeat = false;
    // crucian(bool freshWater) : freshWater(true) {}

   protected:
    bool freshWater;
};

class whale : public Fish {
   public:
    //  **  generally situation
    //    whale() {
    //        freshWater = false;
    //        cout << "a whale is coming!" << endl;
    //    }

    //    bool eatMeat = true;
    // whale(bool freshWater) : freshWater(false) {}

   protected:
    bool freshWater;
};

int main() {
    /**
     * @brief the use of bind, std::ref, std::cref
     */
    //    int n1 = 1, n2 = 2, n3 = 3;
    //    std::function<void()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
    //    n1 = 10;
    //    n2 = 11;
    //    n3 = 12;
    //    std::cout << "Before function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';
    //    bound_f();
    //    std::cout << "After function: " << n1 << ' ' << n2 << ' ' << n3 << '\n';

    /**
     * @brief lambda operator
     */
    //    int a = 1;
    //    int b = 1;
    //    auto ifReturn = [&](int a, int b) {
    //        a + b;
    //        cout << "it has been run" << endl;
    //    };
    //    // int c = ifReturn(1, 1);  //must write "return a+b" in the {}
    //    // cout << ifReturn(a, b) << endl;
    //    ifReturn(a, b);
    //    return 0;

    /**
     * @brief global variance test: can not be changed in the subfunction, but in the main
     */
    //    sum(x_global, y_global);
    //    cout << x_global << y_global << endl;

    //    x_global = 10;
    //    y_global = 11;
    //    cout << x_global << y_global << endl;
    // cout << c << endl;

    /**
     * @brief get the size of C++ standard variances
     */
    //    cout << "size of bool " << sizeof(bool) << endl;
    //    cout << "size of char " << sizeof(char) << endl;
    //    cout << "size of unsigned short int " << sizeof(unsigned short int) << endl;
    //    cout << "size of short int " << sizeof(short int) << endl;
    //    cout << "size of int " << sizeof(int) << endl;
    //    cout << "size of int " << sizeof(int) << endl;
    //    cout << "size of int " << sizeof(int) << endl;
    //    cout << "size of int " << sizeof(int) << endl;
    //    cout << "size of int " << sizeof(int) << endl;
    //    cout << "size of int " << sizeof(int) << endl;
    //    cout << "size of int " << sizeof(int) << endl;
    //    cout << "size of int " << sizeof(int) << endl;
    //    cout << "size of int " << sizeof(int) << endl;
    //    cout << "size of int " << sizeof(int) << endl;

    /**
     * @brief The QT in this version dosen`t support the keyword constexpr
     */
    // constexpr double getPi() { return 3.1415926; }  // wrong
    // constexpr int f() { return 0; }
    // cout << getPi() << endl;

    /**
     * @brief if you don`t define the first variance in enum, the value of it will be 0
     */
    // cout << "Mon = " << Mon << endl;

    /**
     * @brief try to verify the directory_iterator, but the reference is always wrong
     */
    //    // check root folder exists
    //    path rootPath("/home/beyoung/work/TestCache/testCache");
    //    if (!exists(rootPath)) {
    //        cout << "root folder \"" << rootPath.string() << "\" not exists";
    //        return -1;
    //    }
    //    // load data from each folder, and then fusion
    //    directory_iterator itEnd;
    //    for (directory_iterator it(rootPath); it != itEnd; ++it) {
    //        cout << "it is a directory" << endl;
    //    }

    /**
     * @brief try to use cin and getline, but it can not end the inputting by use enter or ctrl+z
     */
    //    string FirstLine;
    //    cout << "Input the firstLine: " << endl;
    //    getline(cin, FirstLine);
    //    string SecondLine;
    //    cout << "Input the secondLine: " << endl;
    //    getline(cin, SecondLine);
    //    cout << "all the lines are: " << FirstLine + SecondLine << endl;

    // 问候用户
    //    std::string name;
    //    std::cout << "What is your name? ";
    //    std::getline(std::cin, name);
    //    std::cout << "Hello " << name << ", nice to meet you.\n";

    //    // 逐行读文件
    //    std::istringstream input;
    //    input.str("1\n2\n3\n4\n5\n6\n7\n");
    //    int sum = 0;
    //    for (std::string line; std::getline(input, line);) {
    //        sum += std::stoi(line);
    //    }
    //    std::cout << "\nThe sum is: " << sum << "\n";

    /**
     * @brief try to use << as the multiple operation, a<<1 equals to a*2, and a<<1+1 = a*2*2 ~= (a<<1)+1
     */
    //    int a = 5, b = 0, c = 0;
    //    b = a << 1 + 5 << 1;
    //    c = ((a << 1) + 5) << 1;
    //    cout << b << endl;
    //    cout << c << endl;

    /**
     * @brief for will not end cause there is an assignment
     */
    //    int count = 0;
    //    for (count; count = 10; ++count) {
    //        cout << "count: " << count << endl;
    //    }
    //    cout << "count: " << count << endl;

    /**
     * @brief try to use chrono but it can not be cout
     */
    // auto t = chrono::steady_clock::now();

    /**
     * @brief overload the function, the return type and function name must be the same
     */
    //    double radius = 3.12;
    //    double height = 6.24;
    //    double pi = 3.1415926;
    //    // double vSphere = volume(radius, pi); //when the pi in the daclaration of function is passed by the
    //    number
    //    // directly and initialized to a initial value, there can be no value pass like the next line or still
    //    pass a
    //    value
    //    // which can be different to the initial value like this line
    //    double vSphere = volume(radius);
    //    double vCylinder = volume(radius, pi, height);
    //    cout << "volume of sphere: " << vSphere << endl;
    //    cout << "volume of cylinder: " << vCylinder << endl;

    /**
     * @brief
     */
    // case1: the initiate of a pointer, and the example of a normal pointer points to a const variance
    //    const int number = 5;
    //    int a = number;
    //    cout << "a = " << a << endl;

    //    const int* aPoint = &a;  // must initiate a pointer with the address of a declared variance or NULL
    //    cout << "*aPoint = " << *aPoint << endl;

    //    // int* bPoint = aPoint; //can not convert the 'const' to a 'non-const'

    // case1.1: another example of a normal pointer points to a const variance
    //    int a = 3;
    //    const int* pNum = &a;  // the value that pointed by pointer pNum has been set as a const in this line
    //    cout << "*pNum = " << *pNum << endl;
    //    //*pNum = 4;  // so the value cannot be changed, and this line will go wrong
    //    int b = 4;
    //    pNum = &b;
    //    cout << "*pNum = " << *pNum
    //         << endl;  // but the address the pointer points to is not a const, so the address can be changed

    // case2: a const pointer points to a normal variance
    //    int a = 3;
    //    int* const pNum = &a;  // the address of the variance pointed by the pointer, that is the value in the
    //                           // pointer is set as a const
    //    cout << "*pNum = " << *pNum << endl;
    //    *pNum = 4;
    //    cout << "*pNum = " << *pNum
    //         << endl;  // the value of the variance pointed  by the pointer can be changed because it is not the
    //         const
    //    int b = 4;
    //    // pNum = &b;  // this line will go wrong because the value in the pointer, that is the address of the
    //    pointing
    //    // variance is set to be a const

    // case3: a const pointer points to a const variance
    //    int a = 3;
    //    const int* const pNum = &a;  // this line set the value in pointer and the value in the variance both as
    //    the
    //    const
    //    cout << "*pNum = " << *pNum << endl;
    //    int b = 5;
    //    // pNum = &b;  // this will go wrong, because the value in the pointer has been set as a const
    //    //*pNum = b;  // this will go wrong, because the value in the variance pointed by the pointer has been set
    //    as
    //    a
    //    //const

    /**
     * @brief class
     */
    // 1. the kinds of constructors
    //    Human def;
    //    isAdult(def);
    //    Human Lily("Lily");
    //    isAdult(Lily);
    //    Human Bob("Bob", 70);
    //    isAdult(Bob);

    // crucian lunch;
    //    cout << "-----my lunch is coming!-----" << endl;

    //    if (lunch.eatMeat == true) {
    //        cout << "I eat what eats meat!" << endl;
    //    } else {
    //        cout << "I eat what dose not eat meat!" << endl;
    //    }
    //    lunch.swim();

    // whale dinner;
    //    cout << "-----my dinner is coming!-----" << endl;
    //    if (dinner.eatMeat == true) {
    //        cout << "I eat what eats meat!" << endl;
    //    } else {
    //        cout << "I eat what dose not eat meat!" << endl;
    //    }
    //    dinner.swim();

    double z = 3.14 / 2;
    int flag = 1;
    Eigen::Vector3d p(0, 0, 0);
    if (!flag) {
        p << 0, 0, z;
    } else {
        p << 1, 3, 1;
    }
    cout << "p" << p << endl;
    Sophus::SO3d a = Sophus::SO3d::exp(p);
    Eigen::Vector3d b = Sophus::SO3d::exp(p).log();

    double c = Sophus::SO3d::exp(p).log()[2];
    // cout << "Sophus::SO3d::exp(p) = " << a << endl;
    cout << "Sophus::SO3d::exp(p).log() = " << b << endl;
    cout << "Sophus::SO3d::exp(p).log()[2] = " << c << endl;
}
