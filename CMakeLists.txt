cmake_minimum_required(VERSION 3.17)
project(CDataStructureStudy C)

set(CMAKE_C_STANDARD 11)

#add_executable(CDataStructureStudy main.c)

# 遍历项目目录下所有的 .c 文件
file (GLOB_RECURSE files *.c)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.c\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()