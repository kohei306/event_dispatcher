set(target event_dispatcher-test)

add_executable(${target} main.cpp 
  app/app.cpp
  app/app_impl.cpp
  )
  
target_include_directories(${target}
 PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/ComponentA>
 PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/ComponentB>
 PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/ComponentC>
 PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/app/>
)

set(include_dest "lib/${PROJECT_NAME}/include")

target_link_libraries(${target}
  event_dispatcher  
)

set(cmd "${CMAKE_CURRENT_BINARY_DIR}/${target}")

add_test(NAME EventDispatcherTest COMMAND ${cmd} --gtest_output=xml:${CMAKE_CURRENT_BINARY_DIR}/test_results/gtest-${target}.xml)

