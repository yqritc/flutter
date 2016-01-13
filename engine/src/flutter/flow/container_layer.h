// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLOW_CONTAINER_LAYER_H_
#define FLOW_CONTAINER_LAYER_H_

#include <vector>
#include "flow/layer.h"

namespace flow {

class ContainerLayer : public Layer {
 public:
  ContainerLayer();
  ~ContainerLayer() override;

  void Add(std::unique_ptr<Layer> layer);

  void Preroll(PrerollContext* context, const SkMatrix& matrix) override;
  void PrerollChildren(PrerollContext* context, const SkMatrix& matrix);

  void PaintChildren(PaintContext::ScopedFrame& frame) const;

  const std::vector<std::unique_ptr<Layer>>& layers() const { return layers_; }

 private:
  std::vector<std::unique_ptr<Layer>> layers_;

  DISALLOW_COPY_AND_ASSIGN(ContainerLayer);
};

}  // namespace flow

#endif  // FLOW_CONTAINER_LAYER_H_
