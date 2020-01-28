#pragma once

#include <fstream>
#include <string>

#include "test.hpp"

// ------------------------------------------------------------------
class str_len_test: public test {
   friend std::ifstream& operator>>(std::ifstream&, str_len_test&);

   std::string in_str_;

   std::string get_str_len(const std::string& str) const {
      return std::to_string(str.length());
   }

public:
   std::string run() const override {
      return get_str_len(in_str_);
   }
};

// ------------------------------------------------------------------
std::ifstream& operator>>(std::ifstream& is, str_len_test& obj)
{
   is >> obj.in_str_;
   return is;
}