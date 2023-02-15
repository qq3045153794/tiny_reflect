#pragma once

#include <reflect/RegesterClass.h>
#include <iostream>

namespace reflect {
class A :public Object{
public:
  A() = default;
  A(int a, const std::string& b) : a(a), b(b){}
  int a;
  std::string b;
  virtual void show() override {std::cout << "A" << std::endl;}

};

REGESTER_CLASS(A);
REGESTER_FIELD(A, a, int);
REGESTER_FIELD(A, b, string);
}
