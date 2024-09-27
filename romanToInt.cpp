#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
  unordered_map<char, int> umap = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };
  
public:
  int romanToInt(string s) {
    // Repeatedly replace all occurrences of the special cases
    size_t pos = 0;

    // Replace all occurrences of "IV" with "IIII"
    while ((pos = s.find("IV")) != string::npos) {
      s.replace(pos, 2, "IIII");
    }

    // Replace all occurrences of "IX" with "VIIII"
    while ((pos = s.find("IX")) != string::npos) {
      s.replace(pos, 2, "VIIII");
    }

    // Replace all occurrences of "XL" with "XXXX"
    while ((pos = s.find("XL")) != string::npos) {
      s.replace(pos, 2, "XXXX");
    }

    // Replace all occurrences of "XC" with "LXXXX"
    while ((pos = s.find("XC")) != string::npos) {
      s.replace(pos, 2, "LXXXX");
    }

    // Replace all occurrences of "CD" with "CCCC"
    while ((pos = s.find("CD")) != string::npos) {
      s.replace(pos, 2, "CCCC");
    }

    // Replace all occurrences of "CM" with "DCCCC"
    while ((pos = s.find("CM")) != string::npos) {
      s.replace(pos, 2, "DCCCC");
    }

    // Calculate the result by summing the values of the modified string
    int result = 0;
    for (auto c : s) {
      result += this->umap[c];
    }

    return result;
  }
};
