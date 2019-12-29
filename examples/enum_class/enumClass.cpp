#include <iostream>
#include <string>

using namespace std;

enum class CameraDeviceType : char {
    iPhone6,   // iPhone6 cameraParams
    iPhone6s,  //  iPhone6s cameraParams
    iPhone8,   //  iPhone8 cameraParams
};

/**
 * @brief checkDeviceType
 * @param deviceTypeNum
 * @return it is ok
 */
string enumClassToString(CameraDeviceType deviceTypeNum = CameraDeviceType::iPhone6) {
    string deviceType;
    //    if (deviceTypeNum == CameraDeviceType::iPhone6) {
    //        cout << "my device type is iphone6" << endl;
    //    }
    switch (deviceTypeNum) {
        case CameraDeviceType::iPhone6:
            deviceType = "iPhone 6";
            return deviceType;
            break;
        case CameraDeviceType::iPhone6s:
            deviceType = "iPhone 6s";
            return deviceType;
            break;
        case CameraDeviceType::iPhone8:
            deviceType = "iPhone 8";
            return deviceType;
            break;
        default:
            break;
    }
}

/**
 * @brief stringToEnumClass
 * @param deviceType
 * @return it is ok
 */
CameraDeviceType stringToEnumClass(string& deviceType) {
    CameraDeviceType k;
    if (deviceType == "iPhone 6") {
        cout << "iPhone 6" << endl;
        return k = CameraDeviceType::iPhone6;
    } else if (deviceType == "iPhone 6s") {
        cout << "iPhone 6s" << endl;
        return k = CameraDeviceType::iPhone6s;
    } else {
        cout << "iPhone 8" << endl;
        return k = CameraDeviceType::iPhone8;
    }
}

// if you want a initial value, it must be passed as value but not cite
// void test(int& x(8)) { cout << x << endl; }

int main(int argc, char* argv[]) {
    // int deviceType = 0;
    //    switch (deviceType) {
    //        case static_cast<string>(CameraDeviceType::iPhone6):
    //            cout << "my device type is iphone6" << endl;
    //            break;
    //        default:
    //            break;
    //    }
    //    if (deviceType == static_cast<float>(CameraDeviceType::iPhone6)) {
    //        cout << "my device type is iphone6" << endl;
    //    }
    // printDeviceType(CameraDeviceType::iPhone6);

    // string deviceType = enumClassToString();
    string deviceType = enumClassToString(CameraDeviceType::iPhone8);
    cout << deviceType << endl;

    CameraDeviceType p = stringToEnumClass(deviceType);
    //    cout << static_cast<int>(p) << endl;

    string q = enumClassToString(p);
    cout << q << endl;
    // test();
}
