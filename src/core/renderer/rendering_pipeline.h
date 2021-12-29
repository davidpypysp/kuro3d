#ifndef CORE_RENDERER_RENDERING_PIPELINE_H_
#define CORE_RENDERER_RENDERING_PIPELINE_H_

#include <memory>

#include "src/core/base/material.h"
#include "src/core/base/geometry.h"

namespace kuro {

class RenderingPipeline {
  // Render one mesh with material's shader program and geometry data
  void Draw(const Material& material, const Geometry& geometry) {}

  // Prepare Draw Data
  void PrepareDrawCall() {}

  // Render one frame by gpu (given all mesh, light...)
  void DrawFrame() {}
};

}  // namespace kuro

#endif