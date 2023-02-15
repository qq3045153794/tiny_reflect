#ifndef _REFLECT_REGESTER_CLASS_H_
#define _REFLECT_REGESTER_CLASS_H_

#include <reflect/ClassFactory.h>

#include <string>

namespace reflect {

class RegesterClass {
public:
  RegesterClass(const std::string& class_name, RegesteFunc reg_func);
  RegesterClass(const std::string& class_name, const std::string& fied_name, const std::string& type, std::size_t offset);

};

}

#define REGESTER_CLASS(CLASS_NAME) \
  Object* regester_##CLASS_NAME() { \
    Object* object = new CLASS_NAME(); \
    object->set_class_name(#CLASS_NAME); \
    return object; \
  } \
  reflect::RegesterClass RegesterClass##CLASS_NAME(#CLASS_NAME, regester_##CLASS_NAME)

#define REGESTER_FIELD(CLASS_NAME, FIELD_NAME, TYPE) \
  CLASS_NAME CLASS_NAME##FIELD_NAME; \
  reflect::RegesterClass RegesterClass##CLASS_NAME##FIELD_NAME(#CLASS_NAME, #FIELD_NAME, #TYPE, (std::size_t)(&CLASS_NAME##FIELD_NAME.FIELD_NAME) - (std::size_t)(&CLASS_NAME##FIELD_NAME))


#endif

