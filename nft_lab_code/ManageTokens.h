#ifndef MANAGETOKENS_H
#define MANAGETOKENS_H

#include "NfToken.h"
#include <memory>
#include <vector>
#include <string>

class ManageTokens {
private:
    std::string computeHash(const std::string& input);

public:
    std::unique_ptr<NfToken> mintToken(const std::string& name);
    void transferToken(std::vector<std::unique_ptr<NfToken>>& fromWallet,
                       std::vector<std::unique_ptr<NfToken>>& toWallet,
                       size_t index);
};

#endif
