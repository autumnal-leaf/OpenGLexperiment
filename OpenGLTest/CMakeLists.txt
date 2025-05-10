# cmake的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和版本
project(OpenGL_Test VERSION 1.0.0)

# 设置 C++ 标准为 C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 指定源码文件
add_executable(OpenGLTest src/main.cpp)

# 指定头文件目录（对应 tasks.json 中的 include）
target_include_directories(OpenGLTest PRIVATE ${CMAKE_SOURCE_DIR}/include)

# 指定库文件目录（对应 tasks.json 中的 lib）
link_directories(${CMAKE_SOURCE_DIR}/lib)

# 定义库文件路径
# set(GL_LIB_DIR ${CMAKE_SOURCE_DIR}/lib)

# 链接 OpenGL 相关库（注意：顺序可能影响链接）
target_link_libraries(OpenGLTest PRIVATE glut32 opengl glu32)

# 添加库的完整路径

# 指定输出目录（确保它生效）
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/obj")

message(STATUS "LIB DIR: ${CMAKE_SOURCE_DIR}/lib")
file(TO_CMAKE_PATH "${CMAKE_SOURCE_DIR}/lib/glut32.lib" GLUT_LIB_PATH)
message(STATUS "Checking: GLUT LIB at ${GLUT_LIB_PATH}")

# 如果需要指定构建输出路径（可选）
# set_target_properties(OpenGLTest PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/obj
# )