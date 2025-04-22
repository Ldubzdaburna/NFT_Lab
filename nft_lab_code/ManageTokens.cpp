#include "ManageTokens.h"
#include "NfToken.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

std::string ManageTokens::computeHash(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char*)input.c_str(), input.size(), hash);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

std::unique_ptr<NfToken> ManageTokens::mintToken(const std::string& name) {
    std::string hash = computeHash(name + std::to_string(rand()));
    return std::make_unique<NfToken>(name, hash);
}

void ManageTokens::transferToken(std::vector<std::unique_ptr<NfToken>>& fromWallet,
                                 std::vector<std::unique_ptr<NfToken>>& toWallet,
                                 size_t index) {
    if (index < fromWallet.size()) {
        toWallet.push_back(std::move(fromWallet[index]));
        fromWallet.erase(fromWallet.begin() + index);
    }
}
