#include<iostream>
#include<memory>
#include"digit_password_validator.hpp"
#include"symbol_password_validator.hpp"
#include"length_validator.hpp"
#include"case_password_validator.hpp"
#include<assert.h>

using namespace std;
using namespace kmj;

int main(int argc, char* argv[]){
  auto validator1 = std::make_unique<digit_password_validator>(std::make_unique<length_validator>(8));
  assert(validator1->validator("abc123!@#"));
  assert(validator1->validator("abcde!@#"));
  
  auto validator2 = std::make_unique<symbol_password_validator>(
    std::make_unique<case_password_validator>(
      std::make_unique<digit_password_validator>(
        std::make_unique<length_validator>(8))));

  assert(validator2->validator("Abc123!@#"));
  assert(!validator2->validator("Abc123567"));

  return 0;
}
