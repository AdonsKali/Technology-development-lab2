cmake_minimum_required(VERSION 3.16)

project(AbstractFactory LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(AbstractFactory
  main.cpp
  unit.h
  factorylanguage.h
  cppunit.h cppunit.cpp
  csharpunit.h csharpunit.cpp
  csharpfactory.h csharpfactory.cpp
  cppfactory.h cppfactory.cpp
  javaunit.h javaunit.cpp
  javafactory.h javafactory.cpp

)
target_link_libraries(AbstractFactory Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS AbstractFactory
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
