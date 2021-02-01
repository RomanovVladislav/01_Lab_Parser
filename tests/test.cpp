//
// Created by vladislav on 15.12.2020.
//

#include <gtest/gtest.h>
#include <fstream>
#include "table.hpp"

TEST(Example, EmptyTest)
{
  EXPECT_TRUE(true);
}

TEST(Table, FilePathIsCorrect)
{
  std::string FilePath = "../JsonFiles/CorrectJson.json";
  Table table(FilePath);

  std::stringstream Output;
  Output << table << std::endl;
  std::cout << table.PrintAllStudentsInString() << std::endl;

  EXPECT_TRUE(true);
}

TEST(Table, TableIsCorrect)
{
  std::string FilePath = "../JsonFiles/CorrectJson.json";
  Table table(FilePath);

  std::stringstream Output;
  Output << table << std::endl;

  std:: string TrueTable =
      "| name | group|  avg | debt |\n"
      "| Ivanov Petr | 1 | 4.25 | null |\n"
      "| Sidorov Ivan | 31 | 4 | C++ |\n"
      "| Pertov Nikita | IU8-31 | 3.5 | 3 |\n\n";

  EXPECT_EQ(Output.str(), TrueTable);
}

TEST(Table, MistakeInFilePath)
{
  std::string MyError;
  std::string ErrorMessage = "Wrong path of json file: ../JsonFiles/FalsePath.json";

  try
  {
    std::string FilePath = "../JsonFiles/FalsePath.json";
    Table table(FilePath);

    std::stringstream Output;
    Output << table << std::endl;
  }

  catch (std::string Error)
  {
    MyError = Error;
    std::cout << "Mistake is: " << Error << std::endl;
  }

  EXPECT_EQ(MyError,ErrorMessage);
}

TEST(Table, MistakeInDebt)
{
  std::string MyError;
  std::string ErrorMessage = "Debt is not null, string, array\n";

  try
  {
    std::string FilePath = "../JsonFiles/WrongDebt.json";
    Table table(FilePath);
    std::stringstream Output;
    Output << table << std::endl;
  }

  catch (std::string Error)
  {
    MyError = Error;
    std::cout << "Mistake is: " << Error << std::endl;
  }

  EXPECT_EQ(MyError, ErrorMessage);
}

TEST(Table, MistakeInName)
{
  std::string MyError;
  std::string ErrorMessage = "Name is not string\n";

  try
  {
    std::string FilePath = "../JsonFiles/WrongName.json";
    Table table(FilePath);
    std::stringstream Output;
    Output << table << std::endl;
  }

  catch (std::string Error)
  {
    MyError = Error;
    std::cout << "Mistake is: " << Error << std::endl;
  }

  EXPECT_EQ(MyError,ErrorMessage);
}

TEST(Table, MistakeInGroup)
{
  std::string MyError;
  std::string ErrorMessage = "Group is not string, int\n";

  try
  {
    std::string FilePath = "../JsonFiles/WrongGroup.json";
    Table table(FilePath);
    std::stringstream Output;
    Output << table << std::endl;
  }

  catch (std::string Error)
  {
    MyError = Error;
    std::cout << "Mistake is: " << Error << std::endl;
  }

  EXPECT_EQ(MyError,ErrorMessage);
}

TEST(Table, MistakeInAverage)
{
  std::string MyError;
  std::string ErrorMessage ="Average is not null,string,float,int\n";

  try
  {
    std::string FilePath = "../JsonFiles/WrongAvg.json";
    Table table(FilePath);
    std::stringstream Output;
    Output << table << std::endl;
  }

  catch (std::string Error)
  {
    MyError = Error;
    std::cout << "Mistake is: " << Error << std::endl;
  }

  EXPECT_EQ(MyError,ErrorMessage);
}

TEST(Table, MistakeInItems1)
{
  std::string MyError;
  std::string ErrorMessage = "Items don't equal meta\n";

  try
  {
    std::string FilePath = "../JsonFiles/WrongMeta.json";
    Table table(FilePath);
    std::stringstream Output;
    Output << table << std::endl;
  }

  catch (std::string Error)
  {
    MyError = Error;
    std::cout << "Mistake is: " << Error << std::endl;
  }

  EXPECT_EQ(MyError,ErrorMessage);
}

TEST(Table, MistakeInItems2)
{
  std::string MyError;
  std::string ErrorMessage = "Items is not array\n";

  try
  {
    std::string FilePath = "../JsonFiles/WrongItems.json";
    Table table(FilePath);
    std::stringstream Output;
    Output << table << std::endl;
  }

  catch (std::string Error)
  {
    MyError = Error;
    std::cout << "Mistake is: " << Error << std::endl;
  }

  EXPECT_EQ(MyError,ErrorMessage);
}