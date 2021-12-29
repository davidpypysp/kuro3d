#ifndef CORE_BASE_VISUAL_COMP_H_
#define CORE_BASE_VISUAL_COMP_H_

#include "src/core/base/component_base.h"

class VisualComp : public ComponentBase {
 public:
  VisualComp();

  ~VisualComp();

  virtual void Render() = 0;
};