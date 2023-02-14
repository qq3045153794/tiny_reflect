#ifndef _REFLECT_OBJECT_H_
#define _REFLECT_OBJECT_H_
namespace reflect {

class Object {
public:
  virtual void get() = 0;
  virtual void set() = 0;
  virtual void show() = 0;
};

}

#endif
