// Copyright (c) 2019-2020 Monkey D. Core
// Copyright (c) 2009-2018 The Eozi Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef EOZI_SCRIPT_EOZICONSENSUS_H
#define EOZI_SCRIPT_EOZICONSENSUS_H

#include <stdint.h>

#if defined(BUILD_EOZI_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/eozi-config.h>
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBEOZICONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define EOZICONSENSUS_API_VER 1

typedef enum eoziconsensus_error_t
{
    eoziconsensus_ERR_OK = 0,
    eoziconsensus_ERR_TX_INDEX,
    eoziconsensus_ERR_TX_SIZE_MISMATCH,
    eoziconsensus_ERR_TX_DESERIALIZE,
    eoziconsensus_ERR_AMOUNT_REQUIRED,
    eoziconsensus_ERR_INVALID_FLAGS,
} eoziconsensus_error;

/** Script verification flags */
enum
{
    eoziconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    eoziconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    eoziconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    eoziconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    eoziconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    eoziconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    eoziconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    eoziconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = eoziconsensus_SCRIPT_FLAGS_VERIFY_P2SH | eoziconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               eoziconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | eoziconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               eoziconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | eoziconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int eoziconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, eoziconsensus_error* err);

EXPORT_SYMBOL int eoziconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, eoziconsensus_error* err);

EXPORT_SYMBOL unsigned int eoziconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // EOZI_SCRIPT_EOZICONSENSUS_H
