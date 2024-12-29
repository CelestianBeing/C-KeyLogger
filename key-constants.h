#ifndef KEYCONSTANTS_H
#define KEYCONSTANTS_H

#include <map>
#include <string>

class KeyPair {
public:
    KeyPair(const std::string &vk = "", const std::string &name = "") : VKName(vk), Name(name) {}
    std::string VKName;
    std::string Name;
};

class Keys {
public:
    static std::map<int, KeyPair> KEYS;
};

std::map<int, KeyPair> Keys::KEYS = {
    {0xC1, {"[VK_ABNT_C1]", "[Abnt C1]"}},
    // Rest of the key mappings remain unchanged
    {0x06, {"[VK_XBUTTON2]", "[X Button 2 **]"}},
};

#endif // KEYCONSTANTS_H
