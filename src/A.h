#pragma once

#include <reflect/RegesterClass.h>
#include <iostream>
#include <reflect/Object.h>

namespace reflect {
class A :public Object{
public:
  int a;
  virtual void show() override {std::cout << "A" << std::endl;}
  virtual void get() override {}
  virtual void set() override {}

};

REGESTER_CLASS(A);
}
