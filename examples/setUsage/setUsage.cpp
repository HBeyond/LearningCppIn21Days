#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

class gps {
   public:
    gps(double east, double north, double up) : east_(east), north_(north), up_(up) {}
    double east() { return east_; }
    double north() { return north_; }
    double up() { return up_; }

   private:
    double east_;
    double north_;
    double up_;
};

bool operator<(const gps& lhs, const gps& rhs) { return lhs.< rhs.east_; }

using namespace std;
int main(int argc, char* argv[]) {
    set<gps> A;
    unordered_set<gps> B;

    gps one(1.0, 2.0, 3.0);
    gps two(4.0, 5.0, 6.0);
    gps three(7.0, 8.0, 9.0);

    A.insert(two);
    // B.insert(two);
    A.insert(one);
    // B.insert(one);
    A.insert(three);
    // B.insert(three);
    A.insert(two);
    // B.insert(two);

    cout << "set: " << endl;
    //    for (auto i = A.begin(); i != A.end(); ++i) {
    //        cout <<  << ", " << i->north_ << ", " << i->up_ << endl;
    //    }

    //    cout << "unorderd_set: " << endl;
    //    for (auto i = B.begin(); i != B.end(); ++i) {
    //        cout << i->east_ << ", " << i->north_ << ", " << i->up_ << endl;
    //    }

    //    map<int, string> C;
    //    unordered_map<int, string> D;

    //    C.insert(make_pair(4, "Four"));
    //    D.insert(make_pair(4, "Four"));
    //    C.insert(make_pair(2, "Two"));
    //    D.insert(make_pair(2, "Two"));
    //    C.insert(make_pair(6, "Six"));
    //    D.insert(make_pair(6, "Six"));

    //    cout << "map: " << endl;
    //    for (auto i = C.begin(); i != C.end(); ++i) {
    //        cout << i->first << ", " << i->second << endl;
    //    }

    //    cout << "unorderd_map: " << endl;
    //    for (auto i = D.begin(); i != D.end(); ++i) {
    //        cout << i->first << ", " << i->second << endl;
    //    }

    return 0;
}
