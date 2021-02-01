//
// Created by vladislav on 15.12.2020.
//

#ifndef TEMPLATE_STUDENT_HPP
#define TEMPLATE_STUDENT_HPP
#include <iostream>
#include <any>
#include <string>
#include "nlohmann/json.hpp"

using namespace nlohmann;

class Student
{
 public:

  Student(const json& JsonFile);

  auto ScanName(const json& JsonFile) -> std::string;
  auto ScanDebt(const json& JsonFile) -> std::any;
  auto ScanAvg(const json& JsonFile) -> std::any;
  auto ScanGroup(const json& JsonFile) -> std::any;

  void ScanJson(const json& JsonFile);

  std::string GetNameString() const;
  std::string GetGroupString() const;
  std::string GetAvgString() const;
  std::string GetDebtString() const;

  friend std::ostream& operator<<(std::ostream &out, const Student& s);

  std::string PrintStudentInString() const;

 private:

  std::string Name;
  std::any Group;
  std::any Avg;
  std::any Debt;
};

#endif  // TEMPLATE_STUDENT_HPP