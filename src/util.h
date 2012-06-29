#pragma once

#include "common.h"

uint64_t      BioAPI BioUtil_Timestamp();
BioAPI_RETURN        BioUtil_Log ( const char* where, const char* format, ... );

BioAPI_RETURN BioAPI BioUtil_CloneBIR  (const BioAPI_BIR  &dest, BioAPI_BIR  &src);
BioAPI_RETURN BioAPI BioUtil_CloneData (const BioAPI_DATA &dest, BioAPI_DATA &src);
