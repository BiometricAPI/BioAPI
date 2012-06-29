#include "common.h"
#include <cstring>
#include <cstdio>

UUID::UUID(
    uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3, 
    uint8_t v4, uint8_t v5, uint8_t v6, uint8_t v7, 
    uint8_t v8, uint8_t v9, uint8_t v10, uint8_t v11, 
    uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15 )
{
    uuid[ 0] = v0;
    uuid[ 1] = v1;
    uuid[ 2] = v2;
    uuid[ 3] = v3;
    uuid[ 4] = v4;
    uuid[ 5] = v5;
    uuid[ 6] = v6;
    uuid[ 7] = v7;
    uuid[ 8] = v8;
    uuid[ 9] = v9;
    uuid[10] = v10;
    uuid[11] = v11;
    uuid[12] = v12;
    uuid[13] = v13;
    uuid[14] = v14;
    uuid[15] = v15;
}





UUID::UUID(
    const BioAPI_UUID &uuid)
{
    memcpy(this->uuid, uuid, 16);
}





UUID::UUID(
    const BioAPI_UUID *uuid)
{
    memcpy(this->uuid, *uuid, 16);
}  
  
  
  
  
UUID::operator BioAPI_UUID*(void) const {
    return (BioAPI_UUID*) &uuid;
}





std::string UUID::toString() {
    char buf[40];
    sprintf(
        buf, 
        "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
        uuid[0],uuid[1],uuid[2],uuid[3],
        uuid[4],uuid[5],
        uuid[6],uuid[7],
        uuid[8],uuid[9],
        uuid[10],uuid[11],uuid[12],uuid[13],uuid[14],uuid[15]);
    return buf;
}





bool UUID::operator<(const UUID& b) const {
  return memcmp(uuid, b.uuid, 16) < 0;
}





bool UUID::operator==(const UUID& b) const {
  return memcmp(uuid, b.uuid, 16) == 0;
}
