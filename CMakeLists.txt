cmake_minimum_required(VERSION 3.31)
project(QML_GO_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Quick Core5Compat Charts)

qt_standard_project_setup()
qt_add_executable(app MACOSX_BUNDLE frontend/src/main.cpp
                  frontend/src/FileWatcher.cpp)

target_link_libraries(app PRIVATE Qt6::Widgets Qt6::Quick Qt6::Core5Compat
                                  Qt6::Charts)

target_include_directories(app PRIVATE frontend/src/)

target_compile_definitions(app PRIVATE PROJECT_DIR="${CMAKE_SOURCE_DIR}")
qt6_policy(SET QTP0001 NEW)

set(QML_FILES
    frontend/customedModules/Main.qml
    frontend/customedModules/HomeWindow.qml
    frontend/customedModules/BackGround.qml
    frontend/customedModules/InputField.qml
    frontend/customedModules/ButtonImage.qml
    frontend/customedModules/RoundedButton.qml
    frontend/customedModules/MenuPanel.qml
    frontend/customedModules/Profile.qml
    frontend/customedModules/PolarGraph.qml
    frontend/customedModules/Metrics.qml)

set(SOURCE_FILES frontend/src/StarredSearch.hpp frontend/src/StarredSearch.cpp)

set(RESOURCE_FILES
    frontend/icons/search_icon.png frontend/icons/profile_icon.png
    frontend/icons/home_icon.png frontend/icons/stats_icon.png
    frontend/icons/filter_icon.png)

qt_add_qml_module(
  app
  URI
  stockMarket
  VERSION
  1.0
  RESOURCE_PREFIX
  "/QML"
  RESOURCES
  ${RESOURCE_FILES}
  SOURCES
  ${SOURCE_FILES}
  QML_FILES
  ${QML_FILES})

set(WASM_PATH "/Users/hsley13/qt-wasm/qtbase/bin/qt-cmake")
set(WASM_BUILD_DIR "${CMAKE_SOURCE_DIR}/wasm-build")
file(MAKE_DIRECTORY ${WASM_BUILD_DIR})

add_custom_target(
  build_wasm ALL
  COMMAND ${WASM_PATH} ${CMAKE_SOURCE_DIR}
  WORKING_DIRECTORY ${WASM_BUILD_DIR}
  COMMENT "Building WebAssembly version of the project")

if(CMAKE_SYSTEM_NAME STREQUAL "Emscripten")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -flto")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s WASM=1")

  include_directories(${EMSCRIPTEN}/system/include)

  set_target_properties(app PROPERTIES LINK_FLAGS "-lidbfs.js")
endif()

add_dependencies(app build_wasm)
