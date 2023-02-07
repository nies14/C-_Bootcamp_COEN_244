#include <iostream>

bool isPowerOfTwo(int n) {
  if (n <= 0) {
    return false;
  }
  return !(n & (n - 1));
}

int main() {
  int n;
  std::cout << "Enter an integer: ";
  std::cin >> n;

  if (isPowerOfTwo(n)) {
    std::cout << n << " is a power of 2." << std::endl;
  } else {
    std::cout << n << " is not a power of 2." << std::endl;
  }
  return 0;
}