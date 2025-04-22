#include "NfToken.h"

NfToken::NfToken(const std::string& name, const std::string& hash)
    : name(name), hash(hash) {}

std::string NfToken::getName() const {
    return name;
}

std::string NfToken::getHash() const {
    return hash;
}
