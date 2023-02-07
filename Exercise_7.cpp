#include <iostream>

int N;

void andSum(int &even, int &odd) {
  for (int i = 1; i <= N; i++) {
    if (i & 1) {
      odd += i;
    } else {
      even += i;
    }
  }
}

void modSum(int &even, int &odd) {
  for (int i = 1; i <= N; i++) {
    if (i % 2 == 1) {
      odd += i;
    } else {
      even += i;
    }
  }
}

void divSum(int &even, int &odd) {
  for (int i = 1; i <= N; i++) {
    if (i / 2 * 2 != i) {
      odd += i;
    } else {
      even += i;
    }
  }
}

void shiftSum(int &even, int &odd) {
  for (int i = 1; i <= N; i++) {
    if ((i >> 1) << 1 != i) {
      odd += i;
    } else {
      even += i;
    }
  }
}

int main() 
{
    std::cout << "Enter N: ";
    std::cin >> N;

    int even = 0, odd = 0;
    andSum(even, odd);
    std::cout << "andSum - even: " << even << ", odd: " << odd << std::endl;

    even = 0, odd = 0;
    modSum(even, odd);
    std::cout << "modSum - even: " << even << ", odd: " << odd << std::endl;

    even = 0, odd = 0;
    divSum(even, odd);
    std::cout << "divSum - even: " << even << ", odd: " << odd << std::endl;
    return 0;
}