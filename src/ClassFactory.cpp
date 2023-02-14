#include <reflect/ClassFactory.h>

namespace reflect {

void ClassFactory::regester_class(const std::string& class_name, RegesteFunc reg_func) {
  class_dictionary.emplace(class_name, reg_func);
}


ClassFactory& ClassFactory::instand() {
  static ClassFactory i;
  return i;
}

Object* ClassFactory::create_class(const std::string& class_name) {
  if (class_dictionary.count(class_name) > 0){
    auto& reg_func = class_dictionary.at(class_name);
    return reg_func();
  }

  return nullptr;
}

}

