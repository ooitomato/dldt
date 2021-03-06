/*
// Copyright (c) 2016 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "cldnn.h"
/// @addtogroup c_api C API
/// @{
/// @addtogroup c_topology Network Topology
/// @{
/// @addtogroup c_primitives Primitives
/// @{

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Activation using rectified linear unit or parameterized rectified linear unit.
/// @details Can get one negative slope or negative slope per channel.
/// @par Algorithm:
///   out(i,x,y) = max(0, in(i,x,y)) + slope(i) * min(0, in(i,x,y))
/// @par Where:
///   @li out(i,x,y) : value at x, y from i-th feature map after activation.
///   @li in(i,x,y) : value at x, y from i-th feature map before activation.
///   @li slope(i) : the slope value of the i-th feature map (can be shared across channels or one slope per channel).
CLDNN_BEGIN_PRIMITIVE_DESC(activation)
/// @brief activation function.
cldnn_activation_func activation_func;
/// @brief Activation additional params.
/// activation_relu_negative_slope  - additional_params.a is a negative slope
/// activation_brelu                - additional_params.a is a upper bound
/// activation_linear               - additional_params.a/b uses as a*val + b
cldnn_activation_additional_params additional_params;
/// @brief Activation additional params stored on a memory object
/// activation_relu_negative_slope  - negative slope per feature map
/// activation_brelu                - upper bound per feature map
/// activation_linear               - a,b per feature map
cldnn_primitive_id additional_params_input;
CLDNN_END_PRIMITIVE_DESC(activation)

CLDNN_DECLARE_PRIMITIVE_TYPE_ID(activation);

#ifdef __cplusplus
}
#endif

/// @}
/// @}
/// @}
#endif /* ACTIVATION_H */
