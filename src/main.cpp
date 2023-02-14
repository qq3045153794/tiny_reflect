#include <reflect/RegesterClass.h>
#include "A.h"
using namespace reflect;
int main() {
  Object* a = ClassFactory::instand().create_class("A");
  a->show();
  return 0;
}
