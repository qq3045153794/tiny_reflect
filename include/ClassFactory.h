#ifndef _REFLECT_INCLUDE_H_
#define _REFLECT_INCLUDE_H_

#include <string>
#include <map>
#include <unordered_map>

namespace reflect {

class ClassFactory {
public:
  template<typename T>
  T* create_class(const std::string& class_name);

private:
  void regester_class(const std::string& class_name);

  std::unordered_map<std::string, void*> class_dictionary;

};


template<typename T>
T* ClassFactory::create_class(const std::string& class_name) {
  if (class_dictionary.count(class_name) > 0){
    return class_dictionary.at(class_name);
  }

  return nullptr;
}

}
#endif
