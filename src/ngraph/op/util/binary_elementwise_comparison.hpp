//*****************************************************************************
// Copyright 2017-2019 Intel Corporation
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

#include "ngraph/op/op.hpp"
#include "ngraph/op/util/attr_types.hpp"

namespace ngraph
{
    namespace op
    {
        namespace util
        {
            // clang-format off
            /// \brief Abstract base class for elementwise binary comparison operations, i.e.,
            ///        operations where the same scalar binary comparison operation is applied to
            ///        each corresponding pair of elements in two input tensors. Implicit
            ///        broadcast of input tensors is supported through one of the AutoBroadcast
            ///        modes.
            ///
            /// For example, if the underlying comparison operation (determined by the subclass) is
            /// \f$\mathit{op}(x,y)\f$, the input tensors \f$[[x_0,y_0],[z_0,w_0]]\f$ and
            /// \f$[[x_1,y_1],[z_1,w_1]]\f$ will be mapped to
            /// \f$[[\mathit{op}(x_0,x_1),\mathit{op}(y_0,y_1)],[\mathit{op}(z_0,z_1),\mathit{op}(w_0,w_1)]]\f$.
            ///
            /// ## Inputs
            ///
            /// |        | Type                              | Description                                            |
            /// | ------ | --------------------------------- | ------------------------------------------------------ |
            /// | `arg0` | \f$E[d_1,\dots,d_n]~(n \geq 0)\f$ | A tensor of any shape and element type.                |
            /// | `arg1` | \f$E[d_1,\dots,d_n]~(n \geq 0)\f$ | A tensor of the same shape and element type as `arg0`. |
            /// | `autob`| AutoBroadcastSpec                 | Auto broadcast specification.                          |
            ///
            /// ## Output
            ///
            /// | Type                               | Description                                                                                                                                                                                                        |
            /// | ---------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
            /// | \f$\texttt{bool}[d_1,\dots,d_n]\f$ | The tensor \f$T\f$, where \f$T[i_1,\dots,i_n] = \mathit{op}(\texttt{arg0}[i_1,\dots,i_n],\texttt{arg1}[i_1,\dots,i_n])\f$. This will always have the same shape as the input tensors, and the element type `bool`. |
            // clang-format on
            class BinaryElementwiseComparison : public Op
            {
            protected:
                /// \brief Constructs a binary elementwise comparison operation.
                BinaryElementwiseComparison();

                /// \brief Constructs a binary elementwise comparison operation.
                ///
                /// \param arg0 Node that produces the first input tensor.
                /// \param arg1 Node that produces the second input tensor.
                /// \param autob AutoBroadcast mode.
                BinaryElementwiseComparison(const std::shared_ptr<Node>& arg0,
                                            const std::shared_ptr<Node>& arg1,
                                            const AutoBroadcastSpec& autob = AutoBroadcastSpec());

                /// \brief Constructs a binary elementwise comparison operation.
                ///
                /// \param arg0 Output that produces the first input tensor.
                /// \param arg1 Output that produces the second input tensor.
                /// \param autob AutoBroadcast mode.
                BinaryElementwiseComparison(const Output<Node>& arg0,
                                            const Output<Node>& arg1,
                                            const AutoBroadcastSpec& autob = AutoBroadcastSpec());

                /// \brief Constructs a binary elementwise comparison operation.
                ///
                /// \param arg0 Node that produces the first input tensor.
                /// \param arg1 Node that produces the second input tensor.
                /// \param autob AutoBroadcast mode.
                BinaryElementwiseComparison(const std::string& node_type,
                                            const std::shared_ptr<Node>& arg0,
                                            const std::shared_ptr<Node>& arg1,
                                            const AutoBroadcastSpec& autob = AutoBroadcastSpec());

            public:
                void validate_and_infer_types() override;

                const AutoBroadcastSpec& get_autob() const override { return m_autob; }
                void set_autob(const AutoBroadcastSpec& autob) { m_autob = autob; }
                bool supports_auto_broadcast() const override { return true; }
                bool is_binary_elementwise_comparison() const override { return true; }
            private:
                AutoBroadcastSpec m_autob;
            };
        }
    }
}
