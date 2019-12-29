#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

// unary function
// struct and class are both ok
template <typename elementType>
struct DisplayElement {
    int count = 0;

    // if no ++count, this function shuld be a const member function
    void operator()(const elementType& element) {
        ++count;
        std::cout << element << " ";
    }
};

// unary predicate
template <typename numberType>
struct isMultiple {
    numberType divisor;

    // constructor
    isMultiple(const numberType& Divisor) : divisor(Divisor) {}

    bool operator()(const numberType& num) { return (num % divisor == 0); }
};

// binary function
template <typename numberType>
struct multiply {
    numberType operator()(const numberType& ele1, const numberType& ele2) const { return ele1 * ele2; }
};

// binary predicate
struct compareStrNoCase {
    bool operator()(const std::string& str1, const std::string& str2) const {
        std::string str1NoCase, str2NoCase;
        str1NoCase.resize(str1.size());
        str2NoCase.resize(str2.size());
        std::transform(str1.begin(), str1.end(), str1NoCase.begin(), ::tolower);
        std::transform(str2.begin(), str2.end(), str2NoCase.begin(), ::tolower);
        return (str1NoCase < str2NoCase);
    }
};

struct Comb {
   public:
    Comb(double a, double b) : t(a), dis(b) {}
    double t;
    double dis;
};

class A {
   public:
    A(int _a, int _b) {
        a = _a;
        b = _b;
    }
    int a;
    int b;
};

using namespace std;
int main(int argc, char* argv[]) {
    // 1. using of unary function
    vector<int> unaryFucn_int;
    //    for (size_t i = 0; i < 10; ++i) {
    //        unaryFucn_int.emplace_back(i);
    //    }
    //    cout << "show the elements in vector: " << endl;

    // The struct contains a unary function that can receive the result of a for_each who uses the functor of this
    // struct
    DisplayElement<int> Result;
    //    Result = for_each(unaryFucn_int.begin(), unaryFucn_int.end(), DisplayElement<int>());
    //    cout << endl;
    //    cout << "there are " << Result.count << " elements in vector unaryFunc_int" << endl;

    list<char> unaryFucn_char;
    for (char j = 'a'; j < 'k'; ++j) {
        unaryFucn_char.emplace_back(j);
    }
    //    cout << "show the elements in list: " << endl;
    //    for_each(unaryFucn_char.begin(), unaryFucn_char.end(), DisplayElement<char>());
    //    cout << endl;

    //    cout << "please input the divisor(default 1): ";
    //    cin >> divisor;

    // 2. using of unary predicate
    int divisor = 8;
    vector<int> vecInt;
    for (size_t i = 25; i < 32; ++i) {
        vecInt.emplace_back(i);
    }
    auto findElement = find_if(vecInt.begin(), vecInt.end(), isMultiple<int>(divisor));

    //    if (findElement != vecInt.end()) {
    //        cout << "the first element that can be divided by " << divisor << " found in vecInt is: " << *findElement
    //             << endl;
    //    } else {
    //        cout << "there is no element that can be divided by " << divisor << " found in vecInt" << endl;
    //    }

    // 3. using of binary function
    vector<int> Ele1;
    for (size_t i = 0; i < 10; ++i) {
        Ele1.emplace_back(i);
    }
    vector<int> Ele2;
    for (size_t j = 101; j < 111; ++j) {
        Ele2.emplace_back(j);
    }
    vector<int> Ele3;
    Ele3.resize(Ele1.size());
    transform(Ele1.begin(), Ele1.end(), Ele2.begin(), Ele3.begin(), multiply<int>());
    cout << endl;
    //    cout << "elements in Ele1:" << endl;
    //    for_each(Ele1.begin(), Ele1.end(), DisplayElement<int>());
    //    cout << endl;
    //    cout << "elements in Ele2:" << endl;
    //    for_each(Ele2.begin(), Ele2.end(), DisplayElement<int>());
    //    cout << endl;
    //    cout << "elements in Ele3:" << endl;
    //    for_each(Ele3.begin(), Ele3.end(), DisplayElement<int>());
    //    cout << endl;

    // 4. using of binary predicate
    vector<string> nameStr;
    nameStr = {"jack", "Jack", "Ada", "Picaso"};
    //    for_each(nameStr.begin(), nameStr.end(), DisplayElement<string>());
    //    cout << endl;

    // use the default binary predicate
    sort(nameStr.begin(), nameStr.end());
    //    cout << "the default sort from small to large by std::less:" << endl;
    //    for_each(nameStr.begin(), nameStr.end(), DisplayElement<string>());
    //    cout << endl;

    // use the binary predicate we define
    sort(nameStr.begin(), nameStr.end(), compareStrNoCase());
    //    cout << "the default sort from small to large without case:" << endl;
    //    for_each(nameStr.begin(), nameStr.end(), DisplayElement<string>());
    //    cout << endl;

    vector<Comb> combs;
    Comb com1(4.45, 45.34);
    Comb com2(2.243, 23.446);
    Comb com3(12.97, 59.98097);

    combs.emplace_back(com1);
    combs.emplace_back(com2);
    combs.emplace_back(com3);

    sort(combs.begin(), combs.end(), [](Comb a, Comb b) { return a.t < b.t; });
    //    vector<A> test;
    //    for (int i = 0; i < 10; i++) {
    //        A a(i, 10 - i);
    //        test.emplace_back(a);
    //    }
    //    sort(test.begin(), test.end(), [](A x, A y) { return x.a > y.a; });
    for (int i = 0; i < combs.size(); i++) {
        cout << combs[i].t << endl;
    }

    return 0;
}
