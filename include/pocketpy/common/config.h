#pragma once
// clang-format off

#define PK_VERSION				"2.0.0"
#define PK_VERSION_MAJOR            2
#define PK_VERSION_MINOR            0
#define PK_VERSION_PATCH            0

/*************** feature settings ***************/

// Whether to compile os-related modules or not
#ifndef PK_ENABLE_OS                // can be overridden by cmake
#define PK_ENABLE_OS                0
#endif

// Enable this if you are working with multi-threading (experimental)
// This triggers necessary locks to make the VM thread-safe
#ifndef PK_ENABLE_THREAD            // can be overridden by cmake
#define PK_ENABLE_THREAD            0
#endif

// Enable `line_profiler` module and `breakpoint()` function
#ifndef PK_ENABLE_PROFILER          // can be overridden by cmake
#define PK_ENABLE_PROFILER          0
#endif

// GC min threshold
#ifndef PK_GC_MIN_THRESHOLD         // can be overridden by cmake
#define PK_GC_MIN_THRESHOLD         16384
#endif

/*************** debug settings ***************/
// Do not edit the following settings unless you know what you are doing
#define PK_DEBUG_CEVAL_STEP         0
#define PK_DEBUG_MEMORY_POOL        0
#define PK_DEBUG_NO_AUTO_GC         0
#define PK_DEBUG_GC_STATS           0
#define PK_DEBUG_COMPILER           0

#ifndef PK_DEBUG_PRECOMPILED_EXEC
#define PK_DEBUG_PRECOMPILED_EXEC   0
#endif

/*************** internal settings ***************/

// This is the maximum size of the value stack in PyVar units
// The actual size in bytes equals `sizeof(PyVar) * PK_VM_STACK_SIZE`
#define PK_VM_STACK_SIZE            16384

// This is the maximum number of local variables in a function
// (not recommended to change this)
#define PK_MAX_CO_VARNAMES          64

// Hash table load factor (smaller ones mean less collision but more memory)
// For class instance
#define PK_INST_ATTR_LOAD_FACTOR    0.67f
// For class itself
#define PK_TYPE_ATTR_LOAD_FACTOR    0.5f

#ifdef _WIN32
    #define PK_PLATFORM_SEP '\\'
#else
    #define PK_PLATFORM_SEP '/'
#endif

#if PK_ENABLE_THREAD
#define PK_THREAD_LOCAL     thread_local
#else
#define PK_THREAD_LOCAL     static
#endif
