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

#include <iostream>
#include "app.h"
#include "app_impl.h"

#include "event_dispatcher/dispatcher_component_interface.h"
#include "event_dispatcher/event_dispatcher.h"


Application::ApplicationImpl::ApplicationImpl(): component_a(), component_b(), component_c() {
}

Application::ApplicationImpl::~ApplicationImpl() {
}

void Application::ApplicationImpl::Init() {
  component_a.Init();
  component_b.Init();
  component_c.Init();

  event_dispatcher::SubscribeToEvent<event_dispatcher::ResultUpdateEvent>(&Application::ApplicationImpl::CallBackResult, this);
}

void Application::ApplicationImpl::Shutdown() {
  component_a.ShutDown();
  component_b.ShutDown();
  component_c.ShutDown();
}

void Application::ApplicationImpl::Step() {
  // Order matters! See the information flow above Fig.1.
  component_a.Step();
  component_b.Step();
  component_c.Step();
}

void Application::ApplicationImpl::SetVelocity(const float velocity) {
  event_dispatcher::PublishEvent<event_dispatcher::VelocityUpdateEvent>(velocity);
}

void Application::ApplicationImpl::SetAcceleration(const float acceleration) {
  event_dispatcher::PublishEvent<event_dispatcher::AccelerationDataUpdateEvent>(acceleration);
}

float Application::ApplicationImpl::GetResult() {
  return m_result;
}

