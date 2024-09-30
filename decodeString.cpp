#include <string>

using namespace std;

class Solution {
public:
  string decodeString(string s) {
    int idx = 0;
    return decodeString(s, idx);
  }
  string decodeString(string & s, int & idx){
    int k = 0;
    string result = "";
    while (idx < s.size()){
      if (isalpha(s[idx])){
        result += s[idx];
        idx++;
      } else if (isdigit(s[idx])){
        k *= 10;
        k += s[idx] - '0';
        idx++;
      } else if (s[idx] == '['){
        // skip [
        idx++;
        string str = decodeString(s, idx);
        while (k > 0){
          k--;
          result += str;
        }
      } else {
        // skip ]
        idx++;
        return result;
      }
    }
    return result;
  }
};

// af3[a2[c]]

// af3{           asfd
//      a2[     }
//          c ]