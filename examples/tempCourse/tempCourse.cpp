#include <iostream>
#include <vector>

using namespace std;

template <typename T1 = int, typename T2 = double>
T2 Product(const T1& val1, const T2& val2) {
    T2 result;
    result = val1 * val2;
    return result;
}

template <typename T>
void Swap(T& val1, T& val2) {
    cout << "before swapping, val1 = " << val1 << ", val2 = " << val2 << endl;
    T temp;
    temp = val2;
    val2 = val1;
    val1 = temp;
}

template <typename T1 = int, typename T2 = string>
class VectorOperator {
   public:
    // Constructor
    VectorOperator(const vector<T1>& vec1, const vector<T2>& vec2) : vec1_(vec1), vec2_(vec2) {}

    void printVec1() {
        for (auto it : vec1_) {
            cout << it << endl;
        }
    }
    void printVec2() {
        for (auto it : vec2_) {
            cout << it << endl;
        }
    }

   private:
    vector<T1> vec1_;
    vector<T2> vec2_;
};

int main(int argc, char* argv[]) {
    // Product implement, default type
    int a = 3;
    double b = 4.0;
    double c = Product<>(a, b);
    cout << "c = " << c << endl;

    // Product implement, self define type
    double aa = 3.0;
    int bb = 4;
    c = Product<double, int>(aa, bb);
    cout << "c = " << c << endl;

    // Swap implement
    double val1 = 3.4;
    double val2 = 7.8;
    Swap<double>(val1, val2);
    cout << "after swapping, val1 = " << val1 << ", val2 = " << val2 << endl;

    // Swap implement
    string val3 = "abc";
    string val4 = "def";
    Swap<string>(val3, val4);
    cout << "after swapping, val3 = " << val3 << ", val4 = " << val4 << endl;

    // VecOperator implement
    vector<int> vec1 = {0, 1, 2, 3, 4, 5, 6};
    vector<string> vec2 = {"abc", "def", "ghi"};
    VectorOperator<int, string> vecOper(vec1, vec2);
    vecOper.printVec1();
    vecOper.printVec2();

    return 0;
}
