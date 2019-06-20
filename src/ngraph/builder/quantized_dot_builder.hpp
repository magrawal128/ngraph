//*****************************************************************************
// Copyright 2018-2019 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

#pragma once

#include "ngraph/coordinate_diff.hpp"
#include "ngraph/node.hpp"
#include "ngraph/op/quantized_dot.hpp"
#include "quantization_utils.hpp"

using namespace std;
using namespace ngraph;

namespace ngraph
{
    namespace builder
    {
        shared_ptr<Node> QuantizedDotBuilder(const shared_ptr<Node>& input0,
                                             const shared_ptr<Node>& input1,
                                             const shared_ptr<Node>& min_input0,
                                             const shared_ptr<Node>& max_input0,
                                             const shared_ptr<Node>& min_input1,
                                             const shared_ptr<Node>& max_input1,
                                             const shared_ptr<Node>& min_output,
                                             const shared_ptr<Node>& max_output,
                                             const ngraph::element::Type& output_type,
                                             const ngraph::AxisSet& input0_axes,
                                             const ngraph::AxisSet& input1_axes,
                                             const ngraph::AxisSet& output_axes);
    }
}