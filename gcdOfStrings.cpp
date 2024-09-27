#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    string l, s;
    if (str1.size() > str2.size()){
      l = str1;
      s = str2;
    } else {
      l = str2;
      s = str1;
    }

    if (l.substr(0, s.size()) != s){ // cannot be divided, no GCD
      return "";
    } else if(l.substr(0, s.size()).size() == l.size()) {
      return s;
    } else {
      str1 = l.substr(s.size());
      str2 = s;
      return gcdOfStrings(str1, str2);
    }
  }
};
