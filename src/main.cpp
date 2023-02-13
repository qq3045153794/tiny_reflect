#include <reflect/RegesterClass.h>
#include "A.h"
using namespace reflect;
int main() {
  A* a = ClassFactory::instand().create_class<A>("A");
  a->show();
  return 0;
}
