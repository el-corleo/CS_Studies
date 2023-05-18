#include "buffer.h"
#include <iostream>

int main() {
  Buffer<float> f(10);
  f.insert(0.25);
  f.insert(1.0 +
           f.get(0)); // 0 here means the last inserted element in the buffer
  f.insert(3.0);
  std::cout << "store value = " << f.get(0) << std::endl;
  return 0;
}
