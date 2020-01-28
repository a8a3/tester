
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "string_len.hpp"

namespace fs = std::filesystem;

//tests/
//     test1.in
//     test1.out
//     test2.in
//     test2.out
//     ...

constexpr auto test_dir_name = "tests";
constexpr auto in_ext  = ".in";
constexpr auto out_ext = ".out";

// ------------------------------------------------------------------
int main(int, char**) {
   const auto test_dir_path = fs::current_path() / test_dir_name;

   if (!fs::exists(test_dir_path)) {
      std::cerr << test_dir_name << " directory missing\n";
      return 1;
   }

   size_t test_number{1};
   for (const auto& p: fs::directory_iterator(test_dir_path)) {

      if (p.path().extension() == in_ext) {
         const auto out_file_name{p.path().stem().string() + out_ext};
         const auto out_file_path{p.path().parent_path() / out_file_name};
         if (!fs::exists(out_file_path)) {
            std::cerr << out_file_name << " file missing\n";
            return 1;
         }

         std::ifstream in(p.path().string());
         std::ifstream out(out_file_path.string());

         str_len_test slt;
         in >> slt;
         const auto candidate = slt.run();

         std::string expected;
         out >> expected;

         if (candidate == expected) {
            std::cout << "test" << test_number << " passed\n";
         } else {
            std::cout << "test" << test_number << " failed. expected: " << expected << ", got: " << candidate << '\n';
         }
         ++test_number;
      }

   }
   return 0;
}
