#include "iostream"
#include <vector>
#include "map"

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

  virtual ~Person ()
  {}

  void addElement (const Element &e)
  {
    arr_.push_back (e);
  }

  virtual Person<T> *Clone () const
  {
    return new Person<T> (*this);
  }

  virtual void print () const
  {
    std::cout << name_ << " is a " << age_ << " years old Person whose code "
                                              "is " << code_ << std::endl;
  }

  friend std::ostream &operator<< (const std::ostream &output, const
  Person<T> &p)
  {
    p.print ();
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

  virtual Teacher<T> *Clone () const
  {
    return new Teacher<T> (*this);
  }

  void print () const override
  {
    std::cout << this->name_ << " is a " << this->age_ << " years old "
                                                          "Person whose code"
                                                          " is " << this->code_
              << std::endl;
  }

  friend std::ostream &operator<< (const std::ostream &output, const
  Teacher<T> &t)
  {
    t.print ();
  }

 private:
  int _xp;
};

template<typename T>
class Place
{
 public:

  // Defining typedefs:
  typedef Person<T> *value_type;
  typedef typename std::map<std::string, value_type> container_type;
  typedef typename container_type::iterator iterator;
  typedef typename container_type::const_iterator const_iterator;

  Place () = default;

  bool add(const Person<T> &p)
  {
    return true; // To be continued
  }


  // Defining all begin, end combinations with those of std::map
  iterator begin ()
  { return con.begin (); }

  iterator end ()
  { return con.end (); }

  const_iterator begin () const
  { return con.cbegin (); }

  const_iterator end () const
  { return con.cend (); }

  const_iterator cbegin () const
  { return con.cbegin (); }

  const_iterator cend () const
  { return con.cend (); }

 private:
  std::map<std::string, value_type> con;
};

int main ()
{
  Element e_default;
  Person<int> p1 ("bar", 19, 3);
  Teacher<int> t1 ("miryam", 70, 5, 50);
  Person<int> *dup = p1.Clone ();
  p1.print (); // call Person's print
  t1.print (); // call Teacher's print
  std::cout << p1; // call Person's print
  std::cout << t1; // call Teacher's print

  delete dup;

  // To be continued

  return 0;
}