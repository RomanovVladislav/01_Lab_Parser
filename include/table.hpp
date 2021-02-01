//
// Created by vladislav on 15.12.2020.
//

#ifndef TEMPLATE_TABLE_HPP
#define TEMPLATE_TABLE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include "student.hpp"

class Table
{
 public:

  Table(const std::string& FilePath);

  void ParsingFile(const std::string& FilePath);

  std::string PrintAllStudentsInString();

  friend std::ostream& operator<<(std::ostream &out, const Table& t);

 private:

  std::vector<Student> AllStudents;

};

#endif  // TEMPLATE_JSON_HPP
