#include <reflect/RegesterClass.h>

namespace reflect {

RegesterClass::RegesterClass(const std::string& class_name, RegesteFunc reg_func) {
  auto& factory = ClassFactory::instand();
  factory.regester_class(class_name, reg_func);
}

RegesterClass::RegesterClass(const std::string& class_name, const std::string& fied_name, const std::string& type, std::size_t offset) {
  auto& factory = ClassFactory::instand();
  factory.regester_fied(class_name, fied_name, type, offset);
}

}
