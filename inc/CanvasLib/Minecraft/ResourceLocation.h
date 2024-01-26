#pragma once
#include <string>

typedef uint64_t HashType64;

enum class ResourceFileSystem {
    InUserPackage,
    InAppPackage,
    RawPath,
    InSettingDir,
    InExternalDir,
    InServerPackage,
    InDataDir,
    InUserDir,
    InWorldDir
};

class ResourceLocation {
public:
    ResourceFileSystem mFileSystem;
private:
    std::string mPath;
    uint64_t mPathHash;
    uint64_t mFullHash;

public:
    ResourceLocation() {};
    ResourceLocation(const std::string& path)
        : mFileSystem(ResourceFileSystem::InUserPackage), mPath(path)
    {
        
    }
};
    