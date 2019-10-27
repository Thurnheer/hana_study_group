cmake_minimum_required(VERSION 3.10)

project(boost_hana_fun)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

#find_package(Hana )

add_executable(${PROJECT_NAME}
    main.cpp)

