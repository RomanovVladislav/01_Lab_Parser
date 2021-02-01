//
// Created by vladislav on 15.12.2020.
//

#include "student.hpp"
#include "table.hpp"

Table::Table(const std::string& FilePath)
{
  ParsingFile(FilePath);
}

void Table::ParsingFile(const std::string& FilePath)
{
  std::ifstream File(FilePath, std::ifstream::in);

  if (!File)
    throw std::string("Wrong path of json file: " + FilePath);

  nlohmann::json Data;
  File >> Data;

  if (!Data.at("items").is_array())
    throw std::string("Items is not array\n");

  if (Data.at("items").size() != Data.at("_meta").at("count"))
    throw std::string("Items don't equal meta\n");

  for (auto i = Data.at("items").cbegin(); i < Data.at("items").cend();
       i++)
    AllStudents.push_back(Student(i.value()));
}

std::string Table::PrintAllStudentsInString()
{
  std::string String;
  String = "| name | group|  avg | debt |\n";
  for (auto i = AllStudents.cbegin(); i < AllStudents.cend(); i++)
  {
    String += i->PrintStudentInString();
    String += "\n";
  }
  return String;
}

std::ostream& operator<<(std::ostream& out, const Table& t)
{
  out << "| name | group|  avg | debt |" << std::endl;
  for(size_t i = 0; i < t.AllStudents.size(); i++)
  {
    out << t.AllStudents[i] << std::endl;
  }
  return out;
}