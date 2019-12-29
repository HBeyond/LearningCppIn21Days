#include <iomanip>   // std::cout, std::fixed
#include <iostream>  // std::setprecision
#include <vector>

using namespace std;

// class a {
//   public:
//    double t;
//    double dist;

//    // a& operator=(a& A);
//};

// a& a::operator=(a& A) {
//    t = A.t;
//    dist = A.dist;
//    return *this;
//}

// class b {
//   public:
//    double x;
//    double y;

//    a b_a;
//};

// struct c {
//    int aa;
//    int bb;
//    void set(int aVal, int bVal) {
//        aa = aVal;
//        bb = bVal;
//    }
//};

int main() {
    //    double f = 3.14159;
    //    std::cout << std::setprecision(5) << f << '\n';
    //    std::cout << std::setprecision(9) << f << '\n';
    //    std::cout << std::fixed;  // make the setprecision count the number behind the . symbol
    //    std::cout << std::setprecision(5) << f << '\n';
    //    std::cout << std::setprecision(9) << f << '\n';

    // overload operator =
    //    a A;
    //    a B;
    //    B.dist = 2.4;
    //    B.t = 0.42;
    //    A = B;
    //    cout << A.dist << endl;

    //    b C;
    //    C.x = 0.55;
    //    C.y = 5.5;
    //    C.b_a = B;
    //    cout << C.b_a.dist << endl;

    //    vector<int> a(6, 10);
    //    a = {0, 1, 2, 3, 4, 5};
    //    vector<int>::iterator it = a.begin();
    //    a.erase(a.end() - 1);
    //    for (int i = 0; i < a.size(); ++i) {
    //        cout << "a[" << distance(a.begin(), it) << "] = " << a[i] << endl;
    //        ++it;
    //    }

    //    vector<c> p;
    //    c c1, c2, c3, c4, c5;
    //    c1.set(10, 20);
    //    c2.set(30, 40);
    //    c3.set(50, 60);
    //    c4.set(70, 80);
    //    c5.set(90, 100);
    //    p = {c1, c2, c3, c4, c5};
    //    vector<c>::iterator it = p.begin();
    //    for (it; it < p.end(); ++it) {
    //        cout << it.base()->aa << endl;
    //    }

    //    int k = p.at(3).aa;
    //    cout << k << endl;

    vector<int> test;
    for (size_t i = 0; i < 1000; ++i) {
        test.emplace_back(i);
    }
    for (size_t j = 0; j < test.size(); j += 100) {
        cout << test[j] << endl;
    }
}
