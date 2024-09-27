#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  int compress(vector<char>& chars) {
    int head = 0;
    int tail = 0;
    int counter = 0;

    while(tail <= chars.size()){
      if (tail == chars.size()){
        head++;
        if (counter > 1){
          string str_c = to_string(counter);
          for (int i = 0; i < str_c.size(); i++){
            chars[head] = str_c[i];
            head++;
          }
        }
        return head;
      } else if (chars[head] == chars[tail]){
        counter++;
        tail++;
      } else {
        if (counter > 1){
          string str_c = to_string(counter);
          for (int i = 0; i < str_c.size(); i++){
            chars[++head] = str_c[i];
          }
        }
        chars[head] = chars[tail];
        counter = 0;
      }
    }
    return head;
  }
};

int main(){
  Solution s;
  vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  int num = s.compress(chars);

  for (int i = 0; i < num; i++){
    cout<< chars[i]<< endl;
  }
}