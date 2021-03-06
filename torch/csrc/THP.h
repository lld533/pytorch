#ifndef THP_H
#define THP_H

#include <stdbool.h>
#include <TH/TH.h>
#include <THS/THS.h>

// Back-compatibility macros, Thanks to http://cx-oracle.sourceforge.net/
// define PyInt_* macros for Python 3.x
#ifndef PyInt_Check
#define PyInt_Check             PyLong_Check
#define PyInt_FromLong          PyLong_FromLongLong
#define PyInt_AsLong            PyLong_AsLong
#define PyInt_Type              PyLong_Type
#endif

// By default, don't specify library state (TH doesn't use one)
#define LIBRARY_STATE
#define LIBRARY_STATE_NOARGS
#define LIBRARY_STATE_TYPE

#ifdef _WIN32
# ifdef _THP_CORE
#  define THP_API extern "C" __declspec(dllexport)
#  define THP_CLASS __declspec(dllexport)
# else
#  define THP_API extern "C" __declspec(dllimport)
#  define THP_CLASS __declspec(dllimport)
# endif
#else
# define THP_API extern "C"
# define THP_CLASS
#endif

#include "PtrWrapper.h"
#include "Exceptions.h"
#include "Generator.h"
#include "Storage.h"
#include "Tensor.h"
#include "Size.h"
#include "Module.h"
#include "Types.h"
#include "utils.h" // This requires defined Storage and Tensor types
#include "byte_order.h"

#ifdef _THP_CORE
#include "serialization.h"
#include "allocators.h"

#include "autograd/autograd.h"
#endif

#endif
