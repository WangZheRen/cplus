cmake_minimum_required(VERSION 3.11.2)
project(work)
add_custom_target(cmake-build-debug)

message(STATUS "CMAKE_CXX_COMPILER_ID=${CMAKE_CXX_COMPILER_ID}")


# 编译google test，会在当前目录生成libtest.a静态库
add_subdirectory(lib/ext/googletest)

#头文件
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/include ${PROJECT_SOURCE_DIR}lib/ext/googletest/include /usr/local/include)


link_directories(${PROJECT_SOURCE_DIR}/lib ${PROJECT_SOURCE_DIR}/lib/ext/googletest /usr/local/opt/curl/lib/ /usr/local/lib/ )

#编译器相关设置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/output/bin")
set(LIBRARIES pthread)
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_COMPILER      "clang++" )         # 显示指定使用的C++编译器
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER      "g++" )         # 显示指定使用的C++编译器
set(CMAKE_CXX_FLAGS   "${CMAKE_CXX_FLAGS} -g -Wall")                     # 调试信息,开启所有警告

ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
if (UNIX AND APPLE)
set(CMAKE_CXX_FLAGS   "${CMAKE_CXX_FLAGS} -lboost_locale-mt  -lboost_system-mt -lboost_filesystem-mt")
elseif(UNIX AND NOT APPLE)
set(CMAKE_CXX_FLAGS   "${CMAKE_CXX_FLAGS} -lboost_locale")
endif()

#源码目录
FILE(GLOB_RECURSE SOURCEFILES ${PROJECT_SOURCE_DIR}/src/include/*.cpp)
FILE(GLOB_RECURSE TEST_SOURCEFILES ${PROJECT_SOURCE_DIR}/src/test/*.cpp)

#add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main/main.cpp ${SOURCEFILES})
add_executable(work_relation ${PROJECT_SOURCE_DIR}/src/main/relation.cpp ${SOURCEFILES})
add_executable(work_test ${TEST_SOURCEFILES} ${SOURCEFILES})

#target_link_libraries(${PROJECT_NAME} gtest curl)
target_link_libraries(work_relation gtest curl)
target_link_libraries(work_test gtest curl)


if (UNIX AND APPLE)
execute_process(
    COMMAND bash -c "cp -R ${CMAKE_CURRENT_SOURCE_DIR}/data ${CMAKE_CURRENT_SOURCE_DIR}/output/bin/"
    COMMAND bash -c "cp -R ${CMAKE_CURRENT_SOURCE_DIR}/conf ${CMAKE_CURRENT_SOURCE_DIR}/output/bin/"
)
endif()
