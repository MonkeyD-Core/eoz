Shared Libraries
================

## eoziconsensus

The purpose of this library is to make the verification functionality that is critical to Eozi's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `eoziconsensus.h` located in `src/script/eoziconsensus.h`.

#### Version

`eoziconsensus_version` returns an `unsigned int` with the API version *(currently `1`)*.

#### Script Validation

`eoziconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `eoziconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `eoziconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `eoziconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/eozi/bips/blob/master/bip-0016.mediawiki)) subscripts
- `eoziconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/eozi/bips/blob/master/bip-0066.mediawiki)) compliance
- `eoziconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY` - Enforce NULLDUMMY ([BIP147](https://github.com/eozi/bips/blob/master/bip-0147.mediawiki))
- `eoziconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY` - Enable CHECKLOCKTIMEVERIFY ([BIP65](https://github.com/eozi/bips/blob/master/bip-0065.mediawiki))
- `eoziconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY` - Enable CHECKSEQUENCEVERIFY ([BIP112](https://github.com/eozi/bips/blob/master/bip-0112.mediawiki))
- `eoziconsensus_SCRIPT_FLAGS_VERIFY_WITNESS` - Enable WITNESS ([BIP141](https://github.com/eozi/bips/blob/master/bip-0141.mediawiki))

##### Errors
- `eoziconsensus_ERR_OK` - No errors with input parameters *(see the return value of `eoziconsensus_verify_script` for the verification status)*
- `eoziconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `eoziconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `eoziconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`
- `eoziconsensus_ERR_AMOUNT_REQUIRED` - Input amount is required if WITNESS is used

### Example Implementations
- [NEozi](https://github.com/NicolasDorier/NEozi/blob/master/NEozi/Script.cs#L814) (.NET Bindings)
- [node-libeoziconsensus](https://github.com/bitpay/node-libeoziconsensus) (Node.js Bindings)
- [java-libeoziconsensus](https://github.com/dexX7/java-libeoziconsensus) (Java Bindings)
- [eoziconsensus-php](https://github.com/Bit-Wasp/eoziconsensus-php) (PHP Bindings)
