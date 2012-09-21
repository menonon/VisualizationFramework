project(VisualizationFramework)

cmake_minimum_required(VERSION 2.8)

set(VL_ROOT "/home/menonon/VRJUGGLER")
list(APPEND CMAKE_MODULE_PATH /home/menonon/VRJUGGLER/cmake)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(VRJuggler REQUIRED)
find_package(VL COMPONENTS VLCore VLGraphics VLVolume REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLUT_INCLUDE_DIRS})
include_directories(${VRJUGGLER_INCLUDE_DIRS})
include_directories(${VL_INCLUDE_DIRS})

add_executable(VisualizationFramework
main.cpp
Amaterasu.cpp
Menu.cpp
Config.cpp
Palette.cpp
Coordinates.cpp
Panel.cpp
Data.cpp
UserInterfaces.cpp
VisualizeMethods.cpp
VisualizeMethodsWithVL.cpp
VisualizeMethodsFactory.cpp
VM_Test.cpp
VM_ParticleTracer.cpp
VM_LocalArrows.cpp
VM_MarchingCubes.cpp
)


target_link_libraries(VisualizationFramework
${VRJUGGLER_LIBRARIES}
${VL_LIBRARIES}
${OPENGL_LIBRARIES}
${GLUT_LIBRARIES}
)
