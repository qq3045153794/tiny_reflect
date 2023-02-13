#ifndef _REFLECT_INCLUDE_H_
#define _REFLECT_INCLUDE_H_

#include <string>
#include <map>
#include <unordered_map>

namespace reflect {

typedef void* (*RegesteFunc) (void);

class ClassFactory {
public:
  static ClassFactory& instand();
  template<typename T>
  T* create_class(const std::string& class_name);

  void regester_class(const std::string& class_name, RegesteFunc reg_func);
private:

  std::unordered_map<std::string, RegesteFunc> class_dictionary;

  ClassFactory() {};
  ClassFactory(const ClassFactory&) = delete;
  ClassFactory operator=(const ClassFactory&) = delete;
  ~ClassFactory() {};

};


template<typename T>
T* ClassFactory::create_class(const std::string& class_name) {
  if (class_dictionary.count(class_name) > 0){
    auto& reg_func = class_dictionary.at(class_name);
    return static_cast<T*>(reg_func());
  }

  return nullptr;
}

}
#endif
