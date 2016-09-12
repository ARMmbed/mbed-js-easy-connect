/* Copyright (c) 2016 ARM Limited. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _LIB_EASY_CONNECT_H
#define _LIB_EASY_CONNECT_H

#include "easy_connect-js.h"

DECLARE_JS_WRAPPER_REGISTRATION(easy_connect)
{
  REGISTER_GLOBAL_FUNCTION(easy_connect);
}

#endif // _LIB_EASY_CONNECT_H
