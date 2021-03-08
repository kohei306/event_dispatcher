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

#ifndef INCLUDE_EVENT_DISPATCHER_EVENT_DISPATCHER_H_
#define INCLUDE_EVENT_DISPATCHER_EVENT_DISPATCHER_H_

#include <map>
#include <functional>
#include <string>
#include <utility>
#include <typeindex>
#include "event_dispatcher/multi_thread_model.h"
#include "event_dispatcher/single_thread_model.h"

namespace event_dispatcher {

#define CREATE_EVENT_DATA_MAP(EventTypeName, EventDataType) \
  struct EventTypeName { static const char * name() { return #EventTypeName; }}; \
  EventDataType event_to_type(type_t<EventTypeName>);

template <class T>
struct type_t { using type = T; };

struct NotEventDataType {};

template<class TEvent>
NotEventDataType event_to_type(type_t<TEvent>);

template <class TEvent>
using EventDataType = decltype(event_to_type(type_t<TEvent>()));

template <class TThreadingModel>
class EventDispatcher : public TThreadingModel {
 public:
  using Callback = std::function<void (const void *)>;
  using EventCallbackMap = std::multimap<std::type_index, Callback>;

  static EventDispatcher& GetInstance() {
    static EventDispatcher instance;
    return instance;
  }

  EventDispatcher(EventDispatcher const&) = delete;
  void operator=(EventDispatcher const&) = delete;

  void SubscribeToEvent(std::type_index event_id, Callback cb) {
    TThreadingModel::Lock();
    m_event_cb_map.insert(std::pair<std::type_index, Callback>(event_id, cb));
    TThreadingModel::UnLock();
  }

  void PublishEvent(std::type_index event_id, const void * event_data) {
    TThreadingModel::Lock();
    auto ele = m_event_cb_map.find(event_id);
    if ( ele != m_event_cb_map.end()) {
      ele->second(event_data);
    }

    TThreadingModel::UnLock();
  }

 private:
  EventDispatcher() = default;
  EventCallbackMap m_event_cb_map;
};

template <class T>
using TypeCVRefStripped = typename std::remove_const<typename std::remove_reference<T>::type>::type;

template <class TEvent, class TClass, class TData>
inline void SubscribeToEvent(void (TClass::* callback)(TData), TClass * ptr_class_obj) {
  using DataTypeCVRefStripped = TypeCVRefStripped<TData>;
  static_assert(std::is_same<EventDataType<TEvent>, DataTypeCVRefStripped>::value, "Subscribed Event and Data type of Call back arg is not compatible! Use CREATE_EVENT_DATA_MAP to define the pair.");
  EventDispatcher<SingleThreadModel>::GetInstance().SubscribeToEvent(std::type_index(typeid(TEvent)), [callback, ptr_class_obj](const void * event_data) {
    auto event_data_casted = static_cast<const DataTypeCVRefStripped *>(event_data);
    if (event_data_casted) {
      (ptr_class_obj->*callback)(*event_data_casted);
    }
  });
}

template <class TEvent, class TData>
inline void PublishEvent(TData && event_data) {
  using DataTypeCVRefStripped = TypeCVRefStripped<TData>;
  static_assert(std::is_same<EventDataType<TEvent>, DataTypeCVRefStripped>::value, "Published Event and Data type is not compatible! Use CREATE_EVENT_DATA_MAP to define the pair.");
  EventDispatcher<SingleThreadModel>::GetInstance().PublishEvent(std::type_index(typeid(TEvent)), &event_data);
}

}  // namespace event_dispatcher

#endif  // INCLUDE_EVENT_DISPATCHER_EVENT_DISPATCHER_H_
