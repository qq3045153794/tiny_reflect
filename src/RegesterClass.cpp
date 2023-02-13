#include <reflect/RegesterClass.h>

namespace reflect {

RegesterClass::RegesterClass(const std::string& class_name, RegesteFunc reg_func) {
  auto& factory = ClassFactory::instand();
  factory.regester_class(class_name, reg_func);
}

}
