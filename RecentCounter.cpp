#include <deque>

using namespace std;

class RecentCounter {
private:
  deque<int> buffer;
public:
  RecentCounter() {

  }
  
  int ping(int t) {
    this->buffer.push_back(t);
    while(this->buffer.front() < t-3000) this->buffer.pop_front();
    return (this->buffer.size());
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */