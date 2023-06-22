#include <iostream>
using namespace std;
class Test {
    public:
        int i;
        void get();
};
void Test::get() {
    cout << "Enter the value of i: ";
    cin >> i;
}
Test t;  // Global object
int main() {
    Test t;  // local object
    t.get();
    cout << "value of i in local t: "<<t.i<<'\n';
    ::t.get(); 
    cout << "value of i in global t: "<<::t.i<<'n';
    return 0;
}