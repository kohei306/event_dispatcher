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

#ifndef TEST_COMPONENTA_COMPONENTA_H_
#define TEST_COMPONENTA_COMPONENTA_H_

#include <iostream>
#include "event_dispatcher/dispatcher_component_interface.h"
#include "event_dispatcher/event_dispatcher.h"

#include "event_type_list.h"

class ComponentA : event_dispatcher::IDispatcherComponent {
 public:
	ComponentA() : m_acceleration(0.0) {}

  void Init() {
    event_dispatcher::SubscribeToEvent<event_dispatcher::AccelerationDataUpdateEvent>(&ComponentA::CallBackAcceleration, this);
  }

  void Step() {
    std::cout << "ComponentA Process.." << std::endl;

    float acc_doubled = m_acceleration * 2;  // dummy process to the received data

    event_dispatcher::PublishEvent<event_dispatcher::DoubledAccelerationDataUpdateEvent>(acc_doubled);
  }

  void ShutDown() {
    std::cout << "ComponentA ShutDown.." << std::endl;
  }

  void CallBackAcceleration(const float acceleration) {
    std::cout << "ComponentA Received: " << acceleration << std::endl;
    m_acceleration = acceleration;
  }

 private:
  float m_acceleration;
};

#endif  // TEST_COMPONENTA_COMPONENTA_H_
