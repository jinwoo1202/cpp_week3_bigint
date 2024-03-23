#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string add(string num1, string num2);
string sub(string num1, string num2);

int main(){
    string num1; string num2;

    cout << "First number  >> ";
    cin >> num1;
    cout << "Second number >> ";
    cin >> num2;

    string sum = add(num1, num2);
    string diff = sub(num1, num2);

    cout << "Sum           >> " << sum << endl;
    cout << "Sub           >> " << diff << endl;
    return 0;
}