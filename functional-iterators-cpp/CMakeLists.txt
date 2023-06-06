project(functional-iterators-cpp CXX)

find_package(fmt REQUIRED)
find_package(range-v3 REQUIRED)

set(SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} fmt::fmt range-v3::range-v3)
