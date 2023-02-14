#ifndef _REFLECT_INCLUDE_H_
#define _REFLECT_INCLUDE_H_

#include <string>
#include <map>
#include <unordered_map>
#include <reflect/Object.h>

namespace reflect {

typedef Object* (*RegesteFunc) (void);

class ClassFactory {
public:
  static ClassFactory& instand();
  Object* create_class(const std::string& class_name);

  void regester_class(const std::string& class_name, RegesteFunc reg_func);
  void get(const std::string& class_name, const std::string& value_name);
private:

  std::unordered_map<std::string, RegesteFunc> class_dictionary;

  ClassFactory() {};
  ClassFactory(const ClassFactory&) = delete;
  ClassFactory operator=(const ClassFactory&) = delete;
  ~ClassFactory() {};

};



}
#endif
