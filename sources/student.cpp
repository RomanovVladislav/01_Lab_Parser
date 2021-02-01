//
// Created by vladislav on 15.12.2020.
//

#include <student.hpp>

using nlohmann::json;

Student::Student(const json& JsonFile)
{
  ScanJson(JsonFile);
}

void Student::ScanJson(const json& JsonFile)
{
  Name = ScanName(JsonFile.at("name"));
  Group = ScanGroup(JsonFile.at("group"));
  Avg = ScanAvg(JsonFile.at("avg"));
  Debt = ScanDebt(JsonFile.at("debt"));
}

auto Student::ScanName(const json& JsonFile) -> std::string
{
  if (JsonFile.is_string())
    return JsonFile.get<std::string>();
  else throw (std::string("Name is not string\n"));
}

auto Student::ScanDebt(const json& JsonFile) -> std::any
{
  if (JsonFile.is_null())
    return nullptr;
  else if (JsonFile.is_string())
    return JsonFile.get<std::string>();
  else if (JsonFile.is_array())
    return JsonFile.get<std::vector<std::string>>();
  else throw (std::string("Debt is not null, string, array\n"));
}

auto Student::ScanAvg(const json& JsonFile) -> std::any
{
  if (JsonFile.is_null())
    return nullptr;
  else if (JsonFile.is_string())
    return JsonFile.get<std::string>();
  else if (JsonFile.is_number_float())
    return JsonFile.get<float>();
  else if (JsonFile.is_number_integer())
    return JsonFile.get<int>();
  else throw (std::string("Average is not null,string,float,int\n"));
}

auto Student::ScanGroup(const json& JsonFile) -> std::any
{
  if (JsonFile.is_string())
    return JsonFile.get<std::string>();
  else if (JsonFile.is_number_integer())
    return JsonFile.get<int>();
  else throw (std::string("Group is not string, int\n"));
}

std::string Student::GetNameString() const
{
  return std::any_cast<std::string>(Name);
}

std::string Student::GetGroupString() const
{
  if (Group.type() == typeid(int))
    return std::to_string(std::any_cast<int>(Group));
  else if (Group.type() == typeid(float))
  {
    std::string tmp = std::to_string(std::any_cast<float>(Group));
    while (tmp.at(tmp.size()-1) == '0')
      tmp.pop_back();
    return tmp;
  }
  else
  {
    return std::any_cast<std::string>(Group);
  }
}
std::string Student::GetAvgString() const
{
  if (Avg.type() == typeid(int))
    return std::to_string(std::any_cast<int>(Avg));
  else if (Avg.type() == typeid(float_t))
  {
    std::string tmp = std::to_string(std::any_cast<float>(Avg));
    while (tmp.at(tmp.size()-1) == '0')
      tmp.pop_back();
    return tmp;
  }
  else
  {
    return std::any_cast<std::string>(Avg);
  }
}
std::string Student::GetDebtString() const
{
  if (Debt.type() == typeid(int))
    return std::to_string(std::any_cast<int>(Debt));
  else if (Debt.type() == typeid(std::vector<std::string>))
  {
    int size;
    size = std::any_cast<std::vector<std::string>>(Debt).size();
    //  return "this debt is vector";
    return std::to_string(size);
  }
  else
  {
    if (Debt.type() == typeid(std::nullptr_t))
    {
      return "null";
    }
    else
    {
      return std::any_cast<std::string>(Debt);
    }
  }
}

std::string Student::PrintStudentInString() const
{
  std::string String;
  String = "| " + GetNameString() + " | " + GetGroupString() + " | "
           + GetAvgString() + " | " + GetDebtString() + " |";
  return String;
}

std::ostream& operator<<(std::ostream& out, const Student& s)
{
  out << "| " << s.GetNameString() << " | " << s.GetGroupString()
      << " | " << s.GetAvgString() << " | " << s.GetDebtString()
      << " |";
  return out;
}