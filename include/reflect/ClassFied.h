#ifndef _REFLECT_CLASSFIED_H_
#define _REFLECT_CLASSFIED_H_

#include <string>
namespace reflect {

class ClassField {
public:
  // ClassField(): m_name(""), m_type(""), m_offset(0) {};
  ClassField() = default;
  ClassField(const std::string& name, const std::string& type, std::size_t offset);
  const std::string& name() const;
  const std::string& type() const;
  const std::size_t& offset() const;
private:
  std::string m_name;
  std::string m_type;
  std::size_t m_offset;

};

}

#endif

