
#include <vector>
#include "iostream"


class Element
{
 public:
  Element () = default;

  Element (const std::string &type, double cost) : _type (type), _cost (cost)
  {}

 private:
  std::string _type;
  double _cost;
};

template<typename T>

class Person
{
 protected:
  std::string name_;
  int age_;
  T code_;
  std::vector<Element> arr_;

 public:
  Person ()
  {
    name_ = "";
    age_ = 0;
  }

  Person (const std::string &name, int age, T code)
  {
    name_ = name;
    age_ = age;
    code_ = code;
  }

  void addElement (const Element &e)
  {
    arr_.push_back (e);
  }

  virtual Person<T> *Clone() const
  {
    return new Person<T>(*this);
  }


  virtual void print () const
  {
    std::cout << name_ << " is a " << age_ << " years old Person whose code "
                                              "is " << code_;
  }

};

template<typename T>
class Teacher : public Person<T>
{
 public:

  Teacher () = default;

  Teacher (const std::string &name, int age, T code, int xp) : Person<T>
                                                                   (name, age, code), _xp (xp)
  {}

  void print () const override
  {
    std::cout << this->name_ << " is a " << this->age_ << " years old "
                                                          "Person whose code"
                                                          " is " << this->code_
              << std::endl;
  }

 private:
  int _xp;
};




int main ()
{
  Element e_default;
  Person<int> p1 ("bar", 19, 3);
  Teacher<int> t1("miryam", 70, 5, 50);
  Person<int> *dup = p1.Clone();
  p1.print (); // call Person's print
  t1.print(); // call Teacher's print

  return 0;
}