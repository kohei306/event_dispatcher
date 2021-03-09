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

#ifndef TEST_COMPONENTB_COMPONENTB_H_
#define TEST_COMPONENTB_COMPONENTB_H_

#include <iostream>
#include "event_dispatcher/dispatcher_component_interface.h"
#include "event_dispatcher/event_dispatcher.h"

#include "event_type_list.h"

class ComponentB : event_dispatcher::IDispatcherComponent {
 public:
  void Init() {
	  event_dispatcher::SubscribeToEvent<event_dispatcher::DoubledAccelerationDataUpdateEvent>(&ComponentB::CallBackDoubledAcc, this);
	  event_dispatcher::SubscribeToEvent<event_dispatcher::VelocityUpdateEvent>(&ComponentB::CallBackVelocity, this);
  }

  void Step() {
    std::cout << "ComponentB Process.." << std::endl;
    float velocity_doubled_acc_sum = m_velocity + m_doubled_acc;
    event_dispatcher::PublishEvent<event_dispatcher::VelocityDoubledAccSumUpdateEvent>(velocity_doubled_acc_sum);
  }

  void ShutDown() {
	  std::cout << "ComponentB ShutDown.." << std::endl;
  }

  void CallBackDoubledAcc(const float & doubled_acc) {
    std::cout << "ComponentB Received: " << doubled_acc << std::endl;
    m_doubled_acc = doubled_acc;
  }

  void CallBackVelocity(const float & velocity) {
    std::cout << "ComponentB Received: " << velocity << std::endl;
    m_velocity = velocity;
  }

 private:
  float m_doubled_acc;
  float m_velocity;
};

#endif /* TEST_COMPONENTB_COMPONENTB_H_ */
