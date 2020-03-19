// Copyright (c) 2019-2020 Monkey D. Core
// Copyright (c) 2019-2020 The Eozi Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef EOZI_UTIL_FEES_H
#define EOZI_UTIL_FEES_H

#include <string>

enum class FeeEstimateMode;
enum class FeeReason;

bool FeeModeFromString(const std::string& mode_string, FeeEstimateMode& fee_estimate_mode);
std::string StringForFeeReason(FeeReason reason);

#endif // EOZI_UTIL_FEES_H
