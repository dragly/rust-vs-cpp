project(requirements-cpp CXX)

find_package(fmt REQUIRED)

set(SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} fmt::fmt)
