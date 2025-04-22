#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"
#include "ManageTokens.h"

TEST_CASE("Minting NFTs should produce unique non-empty hashes") {
    ManageTokens manager;
    auto token = manager.mintToken("NFT 1");

    CHECK(token->getHash().size() > 0);
    CHECK(token->getName() == "NFT 1");
}

TEST_CASE("Transferring NFTs between wallets") {
    ManageTokens manager;
    std::vector<std::unique_ptr<NfToken>> walletA;
    std::vector<std::unique_ptr<NfToken>> walletB;

    walletA.push_back(manager.mintToken("NFT Transfer Test"));
    CHECK(walletA.size() == 1);
    CHECK(walletB.empty());

    manager.transferToken(walletA, walletB, 0);

    CHECK(walletA.empty());
    CHECK(walletB.size() == 1);
    CHECK(walletB[0]->getName() == "NFT Transfer Test");
}
