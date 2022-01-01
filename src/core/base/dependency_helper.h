#ifndef CORE_BASE_DEPENDENCY_HELPER_H_
#define CORE_BASE_DEPENDENCY_HELPER_H_

namespace kuro {

#define REGISTER_DEPENDENCY(className, variableName)              \
 protected:                                                       \
  std::shared_ptr<className> variableName;                        \
                                                                  \
 public:                                                          \
  void Register##className(std::shared_ptr<className> instance) { \
    variableName = instance;                                      \
  }

}  // namespace kuro

#endif