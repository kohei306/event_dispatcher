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

#ifndef TEST_COMPONENTC_COMPONENTC_H_
#define TEST_COMPONENTC_COMPONENTC_H_

#include <iostream>
#include "event_dispatcher/dispatcher_component_interface.h"
#include "event_dispatcher/event_type_list.h"
#include "event_dispatcher/event_dispatcher.h"

class ComponentC : event_dispatcher::IDispatcherComponent {
 public:
  void Init() {
	  event_dispatcher::SubscribeToEvent<event_dispatcher::VelocityDoubledAccSumUpdateEvent>(&ComponentC::CallBackVelocityDoubledAccSum, this);
  }

  void Step() {

    std::cout << "ComponentC Process.." << std::endl;
    float result = m_velocity_doubled_acc_sum * 2;
    event_dispatcher::PublishEvent<event_dispatcher::ResultUpdateEvent>(result);
  }

  void ShutDown() {
	  std::cout << "ComponentC ShutDown.." << std::endl;
  }

  void CallBackVelocityDoubledAccSum(const float & velocity_doubled_acc_sum) {
    std::cout << "ComponentC Received: " << velocity_doubled_acc_sum << std::endl;
    m_velocity_doubled_acc_sum = velocity_doubled_acc_sum;
  }

 private:
  float m_velocity_doubled_acc_sum;
};

#endif  // TEST_COMPONENTC_COMPONENTC_H_
