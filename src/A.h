#pragma once

#include <reflect/RegesterClass.h>
#include <iostream>

class A {
public:
  int a;
  void show() {std::cout << "A" << std::endl;}

};

REGESTER_CLASS(A);

