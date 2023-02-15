#include <reflect/RegesterClass.h>
#include "A.h"
using namespace reflect;
int main() {
  Object* a = ClassFactory::instand().create_class("A");
  a->show();
  int nums;
  std::string str = "wsl";
  a->set("a", 11);
  a->set("b", "wsl");

  a->get("a", nums);
  std::string b;
  a->get("b", b);
  std::cout << nums << " " << b << std::endl;

  return 0;
}
