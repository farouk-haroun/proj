#ifndef PROJ__VISIBILITY_CONTROL_H_
#define PROJ__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define PROJ_EXPORT __attribute__ ((dllexport))
    #define PROJ_IMPORT __attribute__ ((dllimport))
  #else
    #define PROJ_EXPORT __declspec(dllexport)
    #define PROJ_IMPORT __declspec(dllimport)
  #endif
  #ifdef PROJ_BUILDING_LIBRARY
    #define PROJ_PUBLIC PROJ_EXPORT
  #else
    #define PROJ_PUBLIC PROJ_IMPORT
  #endif
  #define PROJ_PUBLIC_TYPE PROJ_PUBLIC
  #define PROJ_LOCAL
#else
  #define PROJ_EXPORT __attribute__ ((visibility("default")))
  #define PROJ_IMPORT
  #if __GNUC__ >= 4
    #define PROJ_PUBLIC __attribute__ ((visibility("default")))
    #define PROJ_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define PROJ_PUBLIC
    #define PROJ_LOCAL
  #endif
  #define PROJ_PUBLIC_TYPE
#endif
#endif  // PROJ__VISIBILITY_CONTROL_H_
// Generated 17-Nov-2024 16:48:43
// Copyright 2019-2020 The MathWorks, Inc.
