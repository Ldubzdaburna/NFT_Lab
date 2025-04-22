# NFT Minting and Transfer Lab

This project demonstrates how to create and manage non-fungible tokens (NFTs) using modern C++ features like `unique_ptr`, and secure hashing via OpenSSL.

## Features

- Mint NFTs with a unique name and SHA256 hash
- Store NFTs in digital wallets
- Transfer NFTs between wallets
- Unit tests using Doctest framework

## File Structure

- `NfToken.h / NfToken.cpp` — Represents an NFT with a name and SHA256 hash
- `ManageTokens.h / ManageTokens.cpp` — Manages minting and transferring NFTs
- `main.cpp` — Demonstrates minting and transferring NFTs
- `test_manage_tokens.cpp` — Simple assertion-based unit test
- `test_manage_tokens_doctest.cpp` — Unit test using the Doctest framework

## Compilation Instructions (macOS)

### 1. Install OpenSSL (via Homebrew)

```bash
brew install openssl
```

### 2. Compile with OpenSSL and C++14

If you're on an M1/M2 Mac:

```bash
g++ -std=c++14 main.cpp NfToken.cpp ManageTokens.cpp \
  -I/opt/homebrew/opt/openssl/include \
  -L/opt/homebrew/opt/openssl/lib -lcrypto -o nft_app
```

To run unit tests with Doctest:

```bash
g++ -std=c++14 test_manage_tokens_doctest.cpp NfToken.cpp ManageTokens.cpp \
  -I/opt/homebrew/opt/openssl/include \
  -L/opt/homebrew/opt/openssl/lib -lcrypto -o test_doctest
./test_doctest
```

## Example Usage

```cpp
ManageTokens manager;
auto token = manager.mintToken("My Unique NFT");
walletA.push_back(std::move(token));
manager.transferToken(walletA, walletB, 0);
```

## Author

Lyles Williams
