// main.cpp
#include "ManageTokens.h"
#include <iostream>

int main() {
    ManageTokens manager;
    std::vector<std::unique_ptr<NfToken>> walletA;
    std::vector<std::unique_ptr<NfToken>> walletB;

    walletA.push_back(manager.mintToken("Cool NFT"));
    walletA.push_back(manager.mintToken("Rare NFT"));

    std::cout << "Wallet A - Before Transfer:\n";
    for (const auto& token : walletA)
        std::cout << token->getName() << " : " << token->getHash() << "\n";

    manager.transferToken(walletA, walletB, 0);

    std::cout << "\nWallet A - After Transfer:\n";
    for (const auto& token : walletA)
        std::cout << token->getName() << " : " << token->getHash() << "\n";

    std::cout << "\nWallet B - After Transfer:\n";
    for (const auto& token : walletB)
        std::cout << token->getName() << " : " << token->getHash() << "\n";

    return 0;
}