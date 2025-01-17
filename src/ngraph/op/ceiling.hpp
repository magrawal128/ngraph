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

#include "ngraph/op/util/unary_elementwise_arithmetic.hpp"

namespace ngraph
{
    namespace op
    {
        /// \brief Elementwise ceiling operation.
        class Ceiling : public util::UnaryElementwiseArithmetic
        {
        public:
            NGRAPH_API
            static constexpr NodeTypeInfo type_info{"Ceiling", 0};
            const NodeTypeInfo& get_type_info() const override { return type_info; }
            /// \brief Constructs a ceiling operation.
            Ceiling() = default;
            /// \brief Constructs a ceiling operation.
            ///
            /// \param arg Node that produces the input tensor.
            Ceiling(const Output<Node>& arg);

            virtual std::shared_ptr<Node>
                copy_with_new_args(const NodeVector& new_args) const override;
        };
    }
}
