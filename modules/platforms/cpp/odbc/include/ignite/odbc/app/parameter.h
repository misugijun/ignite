/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _IGNITE_ODBC_APP_PARAMETER
#define _IGNITE_ODBC_APP_PARAMETER

#include <stdint.h>

#include <map>

#include <ignite/guid.h>
#include <ignite/impl/binary/binary_writer_impl.h>
#include <ignite/impl/binary/binary_reader_impl.h>

#include "ignite/odbc/app/application_data_buffer.h"
#include "ignite/odbc/type_traits.h"

namespace ignite
{
    namespace odbc
    {
        namespace app
        {
            /**
             * Statement parameter.
             */
            class Parameter
            {
            public:
                /**
                 * Default constructor.
                 */
                Parameter();

                /**
                 * Constructor.
                 *
                 * @param buffer Underlying data buffer.
                 * @param sqlType IPD type.
                 * @param columnSize IPD column size.
                 * @param decDigits IPD decimal digits.
                 */
                Parameter(const ApplicationDataBuffer& buffer, int16_t sqlType,
                    size_t columnSize, int16_t decDigits);

                /**
                 * Copy constructor.
                 *
                 * @param other Other instance.
                 */
                Parameter(const Parameter& other);

                /**
                 * Destructor.
                 */
                ~Parameter();

                /**
                 * Copy assigment operator.
                 *
                 * @param other Other instance.
                 * @return This.
                 */
                Parameter& operator=(const Parameter& other);

                /**
                 * Write request using provided writer.
                 * @param writer Writer.
                 */
                void Write(ignite::impl::binary::BinaryWriterImpl& writer) const;

                /**
                 * Get data buffer.
                 *
                 * @return underlying ApplicationDataBuffer instance.
                 */
                ApplicationDataBuffer& GetBuffer();

            private:
                /** Underlying data buffer. */
                ApplicationDataBuffer buffer;

                /** IPD type. */
                int16_t sqlType;

                /** IPD column size. */
                size_t columnSize;

                /** IPD decimal digits. */
                int16_t decDigits;
            };

            /** Parameter binging map type alias. */
            typedef std::map<uint16_t, Parameter> ParameterBindingMap;
        }
    }
}

#endif //_IGNITE_ODBC_APP_PARAMETER