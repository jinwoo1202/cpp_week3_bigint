#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string add(string num1, string num2){
    string result;
    int carry = 0;
    int len1 = num1.length();
    int len2 = num2.length();
    int len = max(len1, len2);

    for (int i = 0; i<len; i++){
        int digit1; int digit2;
        if(i<len1)
            digit1 = num1[len1-i-1] - '0';
        else
            digit1=0;
        if(i<len2)
            digit2 = num2[len2-i-1] - '0';
        else
            digit2=0;
        
        int sum = digit1 + digit2 + carry;
        carry = sum/10;
        result.insert(result.begin(), '0' + sum%10);
    }

    if (carry>0){
        result.insert(result.begin(), '0'+carry);
    }

    return result;
}

string sub(string num1, string num2){
    string result;
    int carry=0;
    int len1 = num1.length();
    int len2 = num2.length();
    int len = max(len1, len2);
    bool neg = false;

    if(len1< len2 || (len1==len2 && num1 < num2)){
        swap(num1, num2);
        neg=true;
        len1 = num1.length();
        len2 = num2.length();
    }

    for(int i =0; i<len; ++i){
        int digit1; int digit2;
        if(i<len1)
            digit1 = num1[len1-i-1] - '0';
        else
            digit1=0;
        if(i<len2)
            digit2 = num2[len2-i-1] - '0';
        else
            digit2=0;

        int diff = digit1 - digit2 - carry;
        if(diff < 0){
            diff=diff+10;
            carry=1;
        }
        else {
            carry=0;
        }
        result.insert(result.begin(), '0'+diff);
    }

    if (neg){
        result.insert(result.begin(), '-');
    }

    if (result=="0"){
        return result;
    }

    while(result.size()>1 && result[0]=='0'){
        result.erase(result.begin());
    }

    return result;
}