#ifndef CORE_ENGINE_H_
#define CORE_ENGINE_H_

#include <memory>

#include "src/core/context.h"

namespace kuro {

class Engine {
 public:
  Engine();

  ~Engine();

  void Init();

  template <class T>
  std::shared_ptr<T> GetInstance() {
    return context_->Resolve<T>();
  }

 protected:
  std::shared_ptr<Context> context_;

  void LoadScenario();
};

REGISTER_TYPE_ANNOTATION(Engine)

}  // namespace kuro

#endif  // CORE_ENGINE_H_
