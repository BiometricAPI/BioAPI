#pragma once

#include "common.h"

class UUID {
public:
  BioAPI_UUID uuid;
  
  UUID(
      uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3, 
      uint8_t v4, uint8_t v5, uint8_t v6, uint8_t v7, 
      uint8_t v8, uint8_t v9, uint8_t v10, uint8_t v11, 
      uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15 );
  
  UUID(
      const BioAPI_UUID &uuid);
  
  UUID(
      const BioAPI_UUID *uuid);
  
  operator BioAPI_UUID*() const;  
  bool operator<(const UUID& b) const;
  bool operator==(const UUID& b) const;
  std::string toString();
};

// 
// bool operator==(const UUID& a, const UUID& b);