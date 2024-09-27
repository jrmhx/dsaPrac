#include <iostream>
#include <string>

int main() {
  std::string str = "123";
  if (str.substr(3) == "")
    std::cout << "true" <<std::endl;

  return 0;
}