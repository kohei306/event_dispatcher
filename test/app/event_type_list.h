// MIT License

// Copyright (c) 2018 Kohei Otsuka

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef INCLUDE_EVENT_DISPATCHER_EVENT_TYPE_LIST_H_
#define INCLUDE_EVENT_DISPATCHER_EVENT_TYPE_LIST_H_

#include "event_dispatcher/event_dispatcher.h"

namespace event_dispatcher {

  CREATE_EVENT_DATA_MAP(VelocityUpdateEvent, float)
  CREATE_EVENT_DATA_MAP(AccelerationDataUpdateEvent, float)
  CREATE_EVENT_DATA_MAP(ResultUpdateEvent, float)
  CREATE_EVENT_DATA_MAP(VelocityDoubledAccSumUpdateEvent, float)
  CREATE_EVENT_DATA_MAP(DoubledAccelerationDataUpdateEvent, float)

}  // namespace event_dispatcher

#endif  // INCLUDE_EVENT_DISPATCHER_EVENT_TYPE_LIST_H_
