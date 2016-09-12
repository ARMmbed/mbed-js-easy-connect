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
#include "easy_connect-js.h"
#include "easy-connect.h"

void js_NetworkInterface_destructor(const uintptr_t native_handle)
{
  delete (NetworkInterface*) native_handle;
}

DECLARE_GLOBAL_FUNCTION(easy_connect)
{
  CHECK_ARGUMENT_COUNT(global, easy_connect, (args_count == 0 || args_count == 1));
  CHECK_ARGUMENT_TYPE_ON_CONDITION(global, easy_connect, 0, boolean, (args_count == 1));

  bool enable_logging = false;
  if (args_count == 1) {
    enable_logging = jsmbed_wrap_unbox_boolean(args[0]);
  }

  // NB: easy_connect returns a NetworkInterface*
  uintptr_t network_interface = (uintptr_t) easy_connect(enable_logging);

  jerry_value_t js_object = jsmbed_wrap_create_object();
  jsmbed_wrap_link_objects(js_object, network_interface, js_NetworkInterface_destructor);

  return js_object;
}
