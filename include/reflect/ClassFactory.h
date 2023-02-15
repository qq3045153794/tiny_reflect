#ifndef _REFLECT_INCLUDE_H_
#define _REFLECT_INCLUDE_H_
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <reflect/ClassFied.h>

namespace reflect {

class Object {
public:
  Object() = default;
  virtual void show() = 0;
  const std::string& get_class_name() const {
    return m_clsss_name;
  }

  const void set_class_name(const std::string& class_name) const {
    m_clsss_name = class_name;
  }

  template<typename T>
  void set(const std::string& field_name, const T& value);

  template<typename T>
  void get(const std::string& field_name, T& value);
private:
  mutable std::string m_clsss_name;
};

typedef Object* (*RegesteFunc) (void);

class ClassFactory {
public:
  static ClassFactory& instand();
  Object* create_class(const std::string& class_name);

  void regester_class(const std::string& class_name, RegesteFunc reg_func);

  void regester_fied(const std::string& class_name, const std::string& fied_name, const std::string& type, std::size_t offset);
  ClassField* get_field(const std::string& class_name, const std::string& fied_name);
  int get_field_count(const std::string& class_anme);
private:

  std::unordered_map<std::string, RegesteFunc> class_dictionary;
  std::unordered_map<std::string, std::vector<ClassField*>> field_dictionary;

  ClassFactory() {};
  ClassFactory(const ClassFactory&) = delete;
  ClassFactory operator=(const ClassFactory&) = delete;
  ~ClassFactory() {};

};

template<typename T>
void Object::set(const std::string& field_name, const T& value) {
  ClassFactory& factory = ClassFactory::instand();
  auto& class_name = get_class_name();
  auto* field = factory.get_field(class_name, field_name);
  std::size_t offset = field->offset();
  *(T*)((unsigned char*)(this) + offset) = value;
  std::cout << "set ptr : " << (*(T*)((uint8_t*)(this) + offset)) << " " << value << std::endl;
  std::cout << "ptr : " << (this) << " " << offset << std::endl;
  std::cout << "type : " << typeid(T).name() << std::endl;
}

template<typename T>
void Object::get(const std::string& field_name, T& value) {
  ClassFactory& factory = ClassFactory::instand();
  auto& class_name = get_class_name();
  auto* field = factory.get_field(class_name, field_name);
  std::size_t offset = field->offset();
  std::cout << "get ptr : " << (*(T*)((uint8_t*)(this) + offset)) << std::endl;
  std::cout << "ptr : " << (this) << " " << offset << std::endl;
  std::cout << "type : " << typeid(T).name() << std::endl;
  value = *(T*)((unsigned char*)(this) + offset);
}

}
#endif
