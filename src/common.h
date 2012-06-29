#pragma once

#if defined WIN || defined WIN32 || defined WIN64 || defined _WIN || defined _WIN32 || defined _WIN64
  #define BioAPI_EXPORT extern "C" __declspec(dllexport)
#else
  #define BioAPI_EXPORT extern "C" __attribute__ ((visibility("default")))
#endif

#include <pthread.h>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <utility>

#include <bioapi.h>
#include "util.h"
#include "memory.h"
#include "handle_manager.h"
#include "uuid.h"

class Cancellable;
class Unit;
class UnitArchive;
class UnitMatching;
class UnitProcessing;
class UnitSensor;
class AttachSession;
class BSP;

#include "cancellable.h"
#include "unit.h"
#include "unit_archive.h"
#include "unit_matching.h"
#include "unit_processing.h"
#include "unit_sensor.h"
#include "attach_session.h"
#include "bsp.h"

#define DEFAULT_CAPTURE_TIMEOUT 30000