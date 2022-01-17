#include <string>
#include <map>
#include <memory>
#include <functional>
#include <iostream>
#include <vector>
#include <any>
#include <unordered_map>

class IocContainer {
 private:
  std::unordered_map<std::string, std::any> m_creatorMap;

 private:
  void RegisterType(const std::string& strKey, std::any constructor) {
    if (m_creatorMap.find(strKey) != m_creatorMap.end()) {
      throw std::invalid_argument("this key has already exist");
    }
    m_creatorMap.emplace(strKey, constructor);
  }

 public:
  IocContainer(void) {}
  ~IocContainer(void) {}

  //注册需要创建对象的构造函数，需要传入一个唯一的标识，以便在后面创建对象时方便查找
  template <class T, class Depend>
  void RegisterType(std::string strKey) {
    std::function<T*()> function = [] { return new T(new Depend()); };
    RegisterType(strKey, function);
  }

  //根据唯一的标w识去查找对应的构造器，并创建指针对象
  template <class T>
  T* Resolve(const std::string& strKey) {
    if (m_creatorMap.find(strKey) == m_creatorMap.end()) {
      return nullptr;
    }
    std::any resolver = m_creatorMap[strKey];
    /*std::function<T*()> function = m_creatorMap[strKey];*/
    std::function<T*()> function = std::any_cast<std::function<T*()>>(resolver);
    return function();
  }

  //创建智能指针对象
  template <class T>
  std::shared_ptr<T> ResolveShared(const std::string& strKey) {
    T* ptr = Resolve<T>(strKey);
    return std::shared_ptr<T>(ptr);
  }
};

struct Base {
  virtual void Func() = 0;
  virtual ~Base() {}
};

struct DerivedB : Base {
  void Func() override { std::cout << "call func in DerivedB" << std::endl; }
};

struct DerivedC : Base {
  void Func() override { std::cout << "call func in DerivedC" << std::endl; }
};

struct DerivedD : Base {
  void Func() override { std::cout << "call func in DerivedD" << std::endl; }
};

struct A {
  A(Base* ptr) : m_ptr(ptr) {}
  void Func() { m_ptr->Func(); }

  ~A() {
    if (m_ptr != nullptr) {
      delete m_ptr;
      m_ptr = nullptr;
    }
  }

 private:
  Base* m_ptr;
};

void TestIOC() {
  IocContainer ioc;
  ioc.RegisterType<A, DerivedB>("B");
  ioc.RegisterType<A, DerivedC>("C");
  ioc.RegisterType<A, DerivedD>("D");

  auto paB = ioc.ResolveShared<A>("B");
  paB->Func();
  auto paC = ioc.ResolveShared<A>("C");
  paC->Func();
}

int main() {
  TestIOC();
  return 0;
}