#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(int argc, char* argv[]) {
    // fill and fill_n
    vector<int> a_int(3);
    //    for (size_t i = 24; i < 89; i += 6) {
    //        a_int.emplace_back(i);
    //    }
    fill(a_int.begin(), a_int.end(), 9);
    // for_each(a_int.begin(), a_int.end(), [](const int& a) { cout << a << endl; });
    a_int.resize(6);
    fill_n(a_int.begin() + 3, 3, -9);
    // for_each(a_int.begin(), a_int.end(), [](const int& a) { cout << a << endl; });
    // a_int.clear();
    //    generate(a_int.begin(), a_int.end(), std::rand());

    vector<char> b_char(3);
    for (char index = 'a'; index <= 'z'; ++index) {
        b_char.emplace_back(index);
    }
    // generate(b_char.begin(), b_char.end(), rand());
    // for_each(b_char.begin(), b_char.end(), [](const char& b) { cout << b << endl; });

    vector<string> c_string;
    c_string = {"aaaa", "bbbbb", "cccc", "ddddd", "ka;lsjdfkl;j"};
    // for_each(c_string.begin(), c_string.end(), [](const string& c) { cout << c << endl; });

    struct d {
        int d_int;
        char d_char;
        string d_string;
    };
    vector<d> d_struct;
    for (size_t j = 0; j < 10; ++j) {
        int x = j;
        char y = j;
        string z = "z" + j;
        d temp;
        temp.d_int = j;
        temp.d_char = j;
        temp.d_string = z;
        d_struct.emplace_back(temp);
    }
    // for_each(d_struct.begin(), d_struct.end(), [](const d& d) { cout << d.d_char << endl; });

    // copy and copy_if
    vector<int> e_copy(10);
    auto iNew = copy(a_int.begin(), a_int.end(), e_copy.begin());
    //    for_each(e_copy.begin(), e_copy.end(), [](const int& e) { cout << e << endl; });
    //    cout << "iNew: " << *iNew.base() << endl;
    //    cout << "copy_if" << endl;
    copy_if(a_int.begin(), a_int.end(), iNew, [](const int& ele) { return ele > 0; });
    //    for_each(e_copy.begin(), e_copy.end(), [](const int& ele) { cout << ele << endl; });
    vector<int> f_copy_if(10);
    fill(f_copy_if.begin(), f_copy_if.end(), 1);
    copy_if(a_int.begin(), a_int.end(), f_copy_if.begin(), [](const int& ele) { return ele > 0; });
    //    cout << "f" << endl;
    //    for_each(f_copy_if.begin(), f_copy_if.end(), [](const int& ele) { cout << ele << endl; });

    // remove and remove_if
    vector<int> g_remove = {2, 2, 2, 3, 3, 4, 4, 3, 5, 5};
    for_each(g_remove.begin(), g_remove.end(), [](const int& ele) { cout << ele << endl; });
    auto iRemov = remove(g_remove.begin(), g_remove.end(), 3);
    cout << "after remove" << endl;
    cout << "iRemov = " << *iRemov << endl;
    cout << "last of g_remove = " << *(g_remove.end()) << endl;
    g_remove.erase(iRemov, g_remove.end());
    for_each(g_remove.begin(), g_remove.end(), [](const int& ele) { cout << ele << endl; });
}
