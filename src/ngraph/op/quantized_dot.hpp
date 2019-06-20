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
#include "ngraph/op/op.hpp"

namespace ngraph
{
    namespace op
    {
        class QuantizedDot : public Op
        {
        public:
            /// \brief Constructs a quantized convolution operation.
            ///
            /// \param input0 The node producing the input data batch tensor.
            /// \param input1 The node producing the filters tensor.
            /// \param input0_scale Scale to transform the input
            /// \param input0_zero_point Zero point used for mapping
            /// \param input1_scale Scale to transform the filters
            /// \param input1_zero_point Zero point used for mapping
            /// \param output_scale Scale to transform the output
            /// \param output_zero_point Zero point used for mapping
            /// \param output_type Output element type
            /// \param input0_axes Input axes set for channel wise quantization
            /// \param input1_axes Filter axes set for channel wise quantization
            /// \param output_axes Output axes set for channel wise quantization
            QuantizedDot(const std::shared_ptr<Node>& input0,
                         const std::shared_ptr<Node>& input1,
                         const std::shared_ptr<Node>& input0_scale,
                         const std::shared_ptr<Node>& input0_zero_point,
                         const std::shared_ptr<Node>& input1_scale,
                         const std::shared_ptr<Node>& input1_zero_point,
                         const std::shared_ptr<Node>& output_scale,
                         const std::shared_ptr<Node>& output_zero_point,
                         const element::Type& output_type,
                         const AxisSet& input0_axes,
                         const AxisSet& input1_axes,
                         const AxisSet& output_axes);

            std::shared_ptr<Node> get_input0() { return get_argument(0); }
            std::shared_ptr<Node> get_input1() { return get_argument(1); }
            const ngraph::element::Type& get_output_type() const { return m_output_type; }
            const ngraph::AxisSet& get_input0_axes() const { return m_input0_axes; }
            const ngraph::AxisSet& get_input1_axes() const { return m_input1_axes; }
            const ngraph::AxisSet& get_output_axes() const { return m_output_axes; }
            void validate_and_infer_types() override;
            virtual std::shared_ptr<Node>
                copy_with_new_args(const NodeVector& new_args) const override;

            virtual void generate_adjoints(autodiff::Adjoints& adjoints,
                                           const NodeVector& deltas) override;

        protected:
            ngraph::element::Type m_output_type;
            ngraph::AxisSet m_input0_axes;
            ngraph::AxisSet m_input1_axes;
            ngraph::AxisSet m_output_axes;
        };
    }
}