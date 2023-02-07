#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

const int RANGE = 10;
const int RANGE_SIZE = 100 / RANGE;
const int NUM_STUDENTS = 100;

struct Student {
  std::string name;
  float grade;
};

int main() {
  std::string filename;
  std::ifstream file;
  std::vector<Student> students;

  while (true) {
    std::cout << "Enter filename: ";
    std::cin >> filename;

    file.open(filename);
    if (file.is_open()) {
      break;
    }

    std::cout << "Error: file not found" << std::endl;
  }

  while (students.size() < NUM_STUDENTS && !file.eof()) {
    Student student;
    file >> student.name >> student.grade;
    students.push_back(student);
  }

  int histogram[RANGE_SIZE] = {};
  for (const Student& student : students) {
    int index = std::min((int)student.grade / RANGE, RANGE_SIZE - 1);
    histogram[index]++;
  }

  std::cout << "Histogram:" << std::endl;
  for (int i = 0; i < RANGE_SIZE; i++) {
    if (histogram[i] == 0) {
      continue;
    }

    std::cout << (i * RANGE + 1) << "-" << (i + 1) * RANGE << ": ";
    for (int j = 0; j < histogram[i]; j++) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }

  float sum = 0.0f;
  for (const Student& student : students) {
    sum += student.grade;
  }
  float mean = sum / students.size();

  float deviation = 0.0f;
  for (const Student& student : students) {
    deviation += pow(student.grade - mean, 2);
  }
  deviation = sqrt(deviation / students.size());

  std::string highest_student;
  float highest_grade = 0.0f;
  for (const Student& student : students) {
    if (student.grade > highest_grade) {
      highest_student = student.name;
      highest_grade = student.grade;
    }
  }

  std::cout << "Average grade: " << mean << std::endl;
  std::cout << "Standard deviation: " << deviation << std::endl;
  std::cout << "Highest grade: " << highest_student << " (" << highest_grade << ")" << std::endl;

  return 0;
}