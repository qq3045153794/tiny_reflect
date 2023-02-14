#ifndef _REFLECT_REGESTER_CLASS_H_
#define _REFLECT_REGESTER_CLASS_H_

#include <reflect/ClassFactory.h>

#include <string>

namespace reflect {

class RegesterClass {
public:
  RegesterClass(const std::string& class_name, RegesteFunc reg_func);

};

}

#define REGESTER_CLASS(CLASS_NAME) \
  Object* regester_##CLASS_NAME() { \
    Object* object = new CLASS_NAME(); \
    return object; \
  } \
  reflect::RegesterClass RegesterClass##CLASS_NAME(#CLASS_NAME, regester_##CLASS_NAME)

#endif
