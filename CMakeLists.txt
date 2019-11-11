cmake_minimum_required(VERSION 3.10)

project(boost_hana_fun)

add_executable(${PROJECT_NAME}
    main.cpp)

if(!boost_path)
    include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
else()
    #find_package(Hana REQUIRED PATHS ${boost_path})
    target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${boost_path})
endif()


