#include <reflect/ClassFactory.h>
#include <iostream>

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

void ClassFactory::regester_fied(const std::string& class_name, const std::string& fied_name, const std::string& type, std::size_t offset) {
  field_dictionary[class_name].emplace_back(new ClassField(fied_name, type, offset));
}

ClassField* ClassFactory::get_field(const std::string& class_name, const std::string& fied_name) {
  if (field_dictionary.count(class_name) <= 0) {
    return nullptr;
  }

  for (const auto& field : field_dictionary[class_name]) {
    if(field->name() == fied_name) {
      return field;
    }
  }

  return nullptr;
}

int ClassFactory::get_field_count(const std::string& class_name) {
  if (field_dictionary.count(class_name) <= 0) {
    return 0;
  }
  return field_dictionary[class_name].size();
}

}

