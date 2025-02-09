#pragma once

#include <stdint.h>
#include "ResourceType.h"
#include "libultraship/version.h"
#include "binarytools/BinaryWriter.h"

namespace Ship {
class ResourceMgr;

struct ResourceAddressPatch {
    uint64_t ResourceCrc;
    uint32_t InstructionIndex;
    uintptr_t OriginalData;
};

class Resource {
  public:
    std::shared_ptr<ResourceMgr> ResourceManager;
    Endianness ByteOrder;
    ResourceType Type;
    uint32_t ResourceVersion;
    uint64_t Id;
    bool IsDirty = false;
    std::string Path = "";
    std::vector<ResourceAddressPatch> Patches;
    virtual void* GetPointer() = 0;
    virtual size_t GetPointerSize() = 0;
    virtual ~Resource();
    void RegisterResourceAddressPatch(uint64_t crc, uint32_t instructionIndex, intptr_t originalData);
};
} // namespace Ship
