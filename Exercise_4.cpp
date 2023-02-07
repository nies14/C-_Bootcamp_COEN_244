#include <iostream>

int main() 
{
    int N;
    std::cout << "Enter the length of the sequence: ";
    std::cin >> N;

    int sum_of_numbers = N * (N + 1) / 2;
    int sum_of_sequence = 0;
    int prev = 0;
    int curr = 1;
    for (int i = 1; i < N; i++) 
    {
        int next = prev + curr;
        sum_of_sequence += curr;
        prev = curr;
        curr = next;
    }

    int sum_of_skipped = sum_of_numbers - sum_of_sequence;
    std::cout << "Sum of skipped numbers: " << sum_of_skipped << std::endl;

    return 0;
}




