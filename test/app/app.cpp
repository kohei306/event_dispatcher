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

#include "app.h"
#include "app_impl.h"

Application::Application()
{
  pimpl_ = std::make_unique<ApplicationImpl>();
}

Application::~Application() = default;

void Application::Init()
{
  pimpl_->Init();
}

void Application::Shutdown()
{
  pimpl_->Shutdown();
}

void Application::Step()
{
  pimpl_->Step();
}

void Application::SetVelocity(float velocity)
{
  pimpl_->SetVelocity(velocity);
}

void Application::SetAcceleration(float acceleration)
{
  pimpl_->SetAcceleration(acceleration);
}

float Application::GetResult()
{
  return pimpl_->GetResult();
}