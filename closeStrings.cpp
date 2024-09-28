#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) return false;
    
    int freq1[26] = {0};
    int freq2[26] = {0};
    int bit1 = 0, bit2=0;

    for (int i = 0; i < word1.size(); i++){
      freq1[word1[i]-'a'] ++;
      freq2[word2[i]-'a'] ++;
      bit1 = bit1 | (1 << (word1[i]-'a'));
      bit2 = bit2 | (1 << (word2[i]-'a'));
    }

    if (bit1 != bit2) return false;

    sort(freq1, freq1+26);
    sort(freq2, freq2+26);

    for (int i = 0; i < 26; i++){
      if (freq1[i] != freq2[i]) return false; 
    }

    return true;
  }
};

// lowercase letter
// op1 means freely reorder string abbb -> babb
// op2 means freely reorder freq abbb -> baaa


// cabbba sort-> aabbbc 2 3 1 
// abbccc sort-> abbccc 1 2 3

// sort the words
// ordered_map <char, int> freq1 freq2

// cabbba
// abbccc

