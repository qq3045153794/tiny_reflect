#include <reflect/ClassFied.h>

namespace reflect {

ClassField::ClassField(const std::string& name, const std::string& type, std::size_t offset)
  :m_name(name), m_type(type), m_offset(offset) {}

const std::string& ClassField::name() const {
  return m_name;
}

const std::string& ClassField::type() const {
  return m_type;
}

const std::size_t& ClassField::offset() const {
  return m_offset;
}

}
