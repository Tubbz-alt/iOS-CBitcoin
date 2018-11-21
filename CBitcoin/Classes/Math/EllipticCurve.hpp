//
//  EllipticCurve.hpp
//  CBitcoin
//
//  Created by Wolf McNally on 10/24/18.
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

#ifndef EllipticCurve_hpp
#define EllipticCurve_hpp

#include <stdlib.h>
#include "CBitcoinResult.hpp"

#ifdef __cplusplus
extern "C" {
#endif

    CBitcoinResult _encodeSignature(const uint8_t* ecSignature, uint8_t** derSignature, size_t* derSignatureLength);
    CBitcoinResult _parseSignature(const uint8_t* derSignature, size_t derSignatureSize, bool isStrict, uint8_t** ecSignature, size_t* ecSignatureLength);
    
#ifdef __cplusplus
}
#endif

#endif /* EllipticCurve_hpp */
