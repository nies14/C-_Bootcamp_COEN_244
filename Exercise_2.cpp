#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::string filename = "a.txt";
  //std::cout << "Enter the input filename: ";
  //std::cin >> filename;

  std::ifstream input_file(filename);
  while (!input_file) 
  {
    std::cerr << "Error: Could not open file " << filename << std::endl;
    std::cout << "Enter the input filename: ";
    std::cin >> filename;
    input_file.open(filename);
  }

  std::ofstream error_file("errors.txt");
  int totalSum = 0, lineSum = 0;
  std:: string errorValue = "";
  char c;
  bool flag = true;
  while (input_file.get(c)) 
  {
    //std::cout << "c: " << c<< std::endl;
    if (std::isdigit(c) && flag == true) 
    {
      lineSum = lineSum * 10 + (c - '0');
    } 
    else if (c != '\n')
    {
      flag = false;
      errorValue = errorValue == "" && lineSum != 0 ? std::to_string(lineSum) + c : errorValue+=c;
    }

    else if(c == '\n')
    {
        if(flag == true)
        {
            //std::cout << "lineSum: " <<lineSum<< std::endl;
            totalSum += lineSum;
        }
        else
        {
            //std::cout << "errorValue: " <<errorValue<< std::endl;
            error_file << errorValue << std::endl;
        }
        errorValue = "";
        lineSum = 0;
        flag = true;
    }
  }

  if (errorValue != "")
  {
    error_file << errorValue << std::endl;
  }

  std::cout << "The Sum is: " << totalSum << std::endl;

  input_file.close();
  error_file.close();

  return 0;
}