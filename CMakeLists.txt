cmake_minimum_required(VERSION 3.31)
project(StockMarket LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Quick Core5Compat Charts)

qt_standard_project_setup()
qt_add_executable(app MACOSX_BUNDLE src/main.cpp src/FileWatcher.cpp)

target_link_libraries(app PRIVATE Qt6::Widgets Qt6::Quick Qt6::Core5Compat
                                  Qt6::Charts)

target_include_directories(app PRIVATE src/)

target_compile_definitions(app PRIVATE PROJECT_DIR="${CMAKE_SOURCE_DIR}")
qt6_policy(SET QTP0001 NEW)

set(QML_FILES
    customedModules/Main.qml
    customedModules/HomeWindow.qml
    customedModules/BackGround.qml
    customedModules/InputField.qml
    customedModules/ButtonImage.qml
    customedModules/RoundedButton.qml
    customedModules/RoundedImage.qml
    customedModules/MenuPanel.qml
    customedModules/Profile.qml
    customedModules/PolarGraph.qml
    customedModules/CandleStick.qml
    customedModules/Metrics.qml)

set(SOURCE_FILES
    src/StarredSearch.hpp src/StarredSearch.cpp src/CandleStickModel.hpp
    src/CandleStickModel.cpp src/CandleStickData.hpp src/CandleStickData.cpp)

set(RESOURCE_FILES
    icons/search_icon.png icons/profile_icon.png icons/home_icon.png
    icons/stats_icon.png icons/filter_icon.png)

qt_add_qml_module(
  app
  URI
  StockMarket
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
  COMMAND ${WASM_PATH} ${CMAKE_CURRENT_SOURCE_DIR}
  WORKING_DIRECTORY ${WASM_BUILD_DIR}
  COMMENT "Building WebAssembly version of the project")

if(CMAKE_SYSTEM_NAME STREQUAL "Emscripten")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -flto")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s WASM=3")

  include_directories(${EMSCRIPTEN}/system/include)

  set_target_properties(app PROPERTIES LINK_FLAGS "-lidbfs.js")
endif()

add_dependencies(app build_wasm)
