#ifndef CORE_ENGINE_H_
#define CORE_ENGINE_H_

#include <memory>

#include "src/core/context.h"
#include "src/core/renderer/renderer.h"

namespace kuro {
namespace core {

class Engine {
 public:
  Engine();

  ~Engine();

  void Init();

  template <class T>
  inline std::shared_ptr<T> GetInstance() {
    return context_->Resolve<T>();
  }

  void Draw();

  static std::shared_ptr<Engine> Instance() { return Engine::instance_; }

 protected:
  std::shared_ptr<Context> context_;
  std::shared_ptr<Renderer> renderer_;

  static std::shared_ptr<Engine> instance_;

  void LoadScenario();
};

}  // namespace core

REGISTER_TYPE_ANNOTATION(core::Engine)

}  //  namespace kuro

#endif  // CORE_ENGINE_H_
