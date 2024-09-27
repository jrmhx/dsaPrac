#include <string>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    if (t == "" && s != "") return false;
    else if (s == "") return true;

    for (int i = 0; i < t.size(); i++){
      if (t[i] == s[0]) return isSubsequence(s.substr(1), t.substr(++i));
    }

    return false;

  }
};