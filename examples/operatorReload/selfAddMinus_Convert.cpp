#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Date {
   public:
    Date(int year, int month, int day) : year_(year), month_(month), day_(day) {}

    Date& operator++() {
        ++day_;
        return *this;
    }

    Date& operator--() {
        --day_;
        return *this;
    }

    operator const char*() {
        ostringstream formattedDate;
        formattedDate << "year/month/day: " << year_ << "/" << month_ << "/" << day_ << endl;
        dateInString = formattedDate.str();
        return dateInString.c_str();
    }

    void display() { cout << "year/month/day: " << year_ << "/" << month_ << "/" << day_ << endl; }

   private:
    int day_;
    int month_;
    int year_;
    string dateInString;
};

int main(int argc, char** argv) {
    Date today(2018, 10, 16);
    today.display();
    ++today;
    today.display();
    --today;
    today.display();
    cout << "convert operator reload: " << today << endl;
    return 0;
}
