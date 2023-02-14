#ifndef _REFLECT_INCLUDE_H_
#define _REFLECT_INCLUDE_H_

#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <reflect/Object.h>
#include <reflect/ClassFied.h>

namespace reflect {

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


}
#endif
