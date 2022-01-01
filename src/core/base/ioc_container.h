#ifndef CORE_BASE_IOC_CONTAINER_H_
#define CORE_BASE_IOC_CONTAINER_H_

#include <unordered_map>
#include <memory>

#include "src/utils/type_annotation.h"

namespace kuro {

class IocContainer {
 public:
  template <typename T>
  std::shared_ptr<T> Resolve() {
    const std::string& type_name = TypeAnnotation<T>::Name();
    return type_instance_map[type_name];
  }

  template <typename T>
  std::shared_ptr<T> Register() {
    std::shared_ptr<T> instance = std::make_shared<T>();
    const std::string& type_name = TypeAnnotation<T>::Name();
    type_instance_map[type_name] = instance;
    return instance;
  }

  template <typename Parent, typename Child>
  std::shared_ptr<Parent> Register() {
    std::shared_ptr<Parent> instance = std::make_shared<Child>();
    const std::string& type_name = TypeAnnotation<Parent>::Name();
    type_instance_map[type_name] = instance;
    return instance;
  }

  template <typename T>
  void Register(std::shared_ptr<T> instance) {
    const std::string& type_name = TypeAnnotation<T>::Name();
    type_instance_map[type_name] = instance;
  }

 protected:
  std::unordered_map<std::string, std::shared_ptr<void>> type_instance_map;
};

}  // namespace kuro

#endif