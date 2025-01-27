/* Copyright 2021 Alibaba Group Holding Limited. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#ifndef HYBRIDBACKEND_TENSORFLOW_EMBEDDING_FLOORMOD_SHUFFLE_FUNCTORS_H_
#define HYBRIDBACKEND_TENSORFLOW_EMBEDDING_FLOORMOD_SHUFFLE_FUNCTORS_H_

#if HYBRIDBACKEND_TENSORFLOW

#include <tensorflow/core/framework/tensor.h>
#include <tensorflow/core/public/version.h>

namespace tensorflow {

class OpKernelContext;

namespace hybridbackend {
namespace functor {

template <typename Device, typename T>
struct FloormodShuffle {
  void operator()(const int32 num_partitions, const Tensor& input,
                  Tensor* output, Tensor* sizes, Tensor* indices,
                  OpKernelContext* ctx);
};

template <typename Device, typename T>
struct FloormodShuffleN {
  void operator()(const int32 num_partitions, const std::vector<Tensor>& inputs,
                  std::vector<Tensor*>& outputs,
                  std::vector<Tensor*>& outputs_sizes,
                  std::vector<Tensor*>& outputs_indices, OpKernelContext* ctx);
};

}  // namespace functor
}  // namespace hybridbackend
}  // namespace tensorflow

#endif  // HYBRIDBACKEND_TENSORFLOW
#endif  // HYBRIDBACKEND_TENSORFLOW_EMBEDDING_FLOORMOD_SHUFFLE_FUNCTORS_H_
