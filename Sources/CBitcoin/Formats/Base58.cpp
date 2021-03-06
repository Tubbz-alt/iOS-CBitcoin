//
//  Base58.cpp
//  CBitcoin
//
//  Created by Wolf McNally on 10/22/18.
//  Copyright © 2018 Arciem LLC. All rights reserved.
//
//  Copyright © 2018 Blockchain Commons.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#include "Base58.hpp"
#include <bitcoin/bitcoin.hpp>
#include <string>
#include "Util.hpp"

using namespace libbitcoin;

bool _isBase58Char(char c) {
    return is_base58(c);
}

bool _isBase58String(const char* _Nonnull string) {
    return is_base58(std::string(string));
}

void _encodeBase58(const uint8_t* _Nonnull data, size_t length, char* _Nullable * _Nonnull string, size_t* _Nonnull stringLength) {
    auto s = encode_base58(_toDataSlice(data, length));
    _sendString(s, string, stringLength);
}

CBitcoinResult _decodeBase58(const char* _Nonnull string, uint8_t* _Nullable * _Nonnull data, size_t* _Nonnull dataLength) {
    auto s = std::string(string);
    auto chunk = data_chunk();
    if(!decode_base58(chunk, s)) {
        return CBITCOIN_ERROR_INVALID_FORMAT;
    }
    _sendData(chunk, data, dataLength);
    return CBITCOIN_SUCCESS;
}

void _encodeBase58Check(const uint8_t* _Nonnull data, size_t length, uint8_t version, char* _Nullable * _Nonnull string, size_t* _Nonnull stringLength) {
    auto bytes = to_chunk(version);
    auto payload = _toDataChunk(data, length);
    extend_data(bytes, payload);
    append_checksum(bytes);
    auto s = encode_base58(bytes);
    _sendString(s, string, stringLength);
}

CBitcoinResult _decodeBase58Check(const char* _Nonnull string, uint8_t* _Nullable * _Nonnull data, size_t* _Nonnull dataLength, uint8_t* _Nonnull version) {
    auto s = std::string(string);
    if(s.length() == 0) {
        return CBITCOIN_ERROR_INVALID_FORMAT;
    }
    auto chunk = data_chunk();
    if(!decode_base58(chunk, s)) {
        return CBITCOIN_ERROR_INVALID_FORMAT;
    }
    *version = chunk[0];
    auto slice = data_slice(&*chunk.begin(), &*chunk.end());
    if(!verify_checksum(slice)) {
        return CBITCOIN_ERROR_INVALID_FORMAT;
    }
    auto chunk2 = data_chunk(&*(chunk.begin() + 1), &*(chunk.end() - 4));
    _sendData(chunk2, data, dataLength);
    return CBITCOIN_SUCCESS;
}
