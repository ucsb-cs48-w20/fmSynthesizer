# Install script for directory: /Users/jkilgore/Projects/cs48-fmSynth/fmSynthesizer/fmSynth

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_fmSynth_VST3_to_VST3_binary_locationx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/Users/jkilgore/Library/Audio/Plug-Ins/VST3/fmSynth.vst3")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "/Users/jkilgore/Library/Audio/Plug-Ins/VST3" TYPE DIRECTORY FILES "/Users/jkilgore/Projects/cs48-fmSynth/fmSynthesizer/fmSynth/build/fmSynth.vst3" USE_SOURCE_PERMISSIONS)
    if(EXISTS "$ENV{DESTDIR}/Users/jkilgore/Library/Audio/Plug-Ins/VST3/fmSynth.vst3/Contents/MacOS/fmSynth" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}/Users/jkilgore/Library/Audio/Plug-Ins/VST3/fmSynth.vst3/Contents/MacOS/fmSynth")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "$ENV{DESTDIR}/Users/jkilgore/Library/Audio/Plug-Ins/VST3/fmSynth.vst3/Contents/MacOS/fmSynth")
      endif()
    endif()
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_fmSynth_VST3_to_VST3_binary_locationx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/Users/jkilgore/Library/Audio/Plug-Ins/VST3/fmSynth.vst3")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "/Users/jkilgore/Library/Audio/Plug-Ins/VST3" TYPE DIRECTORY FILES "/Users/jkilgore/Projects/cs48-fmSynth/fmSynthesizer/fmSynth/build/fmSynth.vst3" USE_SOURCE_PERMISSIONS)
    if(EXISTS "$ENV{DESTDIR}/Users/jkilgore/Library/Audio/Plug-Ins/VST3/fmSynth.vst3/Contents/MacOS/fmSynth" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}/Users/jkilgore/Library/Audio/Plug-Ins/VST3/fmSynth.vst3/Contents/MacOS/fmSynth")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "$ENV{DESTDIR}/Users/jkilgore/Library/Audio/Plug-Ins/VST3/fmSynth.vst3/Contents/MacOS/fmSynth")
      endif()
    endif()
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_fmSynth_AU_to_AU_binary_locationx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/Users/jkilgore/Library/Audio/Plug-Ins/Components/fmSynth.component")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "/Users/jkilgore/Library/Audio/Plug-Ins/Components" TYPE DIRECTORY FILES "/Users/jkilgore/Projects/cs48-fmSynth/fmSynthesizer/fmSynth/build/fmSynth.component" USE_SOURCE_PERMISSIONS)
    if(EXISTS "$ENV{DESTDIR}/Users/jkilgore/Library/Audio/Plug-Ins/Components/fmSynth.component/Contents/MacOS/fmSynth" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}/Users/jkilgore/Library/Audio/Plug-Ins/Components/fmSynth.component/Contents/MacOS/fmSynth")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "$ENV{DESTDIR}/Users/jkilgore/Library/Audio/Plug-Ins/Components/fmSynth.component/Contents/MacOS/fmSynth")
      endif()
    endif()
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "x_install_fmSynth_AU_to_AU_binary_locationx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/Users/jkilgore/Library/Audio/Plug-Ins/Components/fmSynth.component")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "/Users/jkilgore/Library/Audio/Plug-Ins/Components" TYPE DIRECTORY FILES "/Users/jkilgore/Projects/cs48-fmSynth/fmSynthesizer/fmSynth/build/fmSynth.component" USE_SOURCE_PERMISSIONS)
    if(EXISTS "$ENV{DESTDIR}/Users/jkilgore/Library/Audio/Plug-Ins/Components/fmSynth.component/Contents/MacOS/fmSynth" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}/Users/jkilgore/Library/Audio/Plug-Ins/Components/fmSynth.component/Contents/MacOS/fmSynth")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "$ENV{DESTDIR}/Users/jkilgore/Library/Audio/Plug-Ins/Components/fmSynth.component/Contents/MacOS/fmSynth")
      endif()
    endif()
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/jkilgore/Projects/cs48-fmSynth/fmSynthesizer/fmSynth/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
