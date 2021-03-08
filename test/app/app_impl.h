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

#ifndef TEST_APP_APP_IMPL_H_
#define TEST_APP_APP_IMPL_H_

#include "componentA.h"
#include "componentB.h"
#include "componentC.h"

class Application::ApplicationImpl {
 public:
  ApplicationImpl();
  ~ApplicationImpl();
  void Init();
  void Shutdown();
  void Step();

  // Temporary example of Setter interface
  void SetVelocity(float velocity);
  void SetAcceleration(float acceleration);

  // Temporary example of Getter interface
  float GetResult();

  void CallBackResult(const float & result) {
    m_result = result;
  }

 private:
  ComponentA component_a;
  ComponentB component_b;
  ComponentC component_c;

  float m_result;
};

#endif  // TEST_APP_APP_IMPL_H_
