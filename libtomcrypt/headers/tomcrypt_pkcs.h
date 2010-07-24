/* LTC_PKCS Header Info */

/* ===> LTC_PKCS #1 -- RSA Cryptography <=== */
#ifdef LTC_PKCS_1

struct algo_properties_st;

enum ltc_pkcs_1_v1_5_blocks
{
  LTC_LTC_PKCS_1_EMSA   = 1,        /* Block type 1 (LTC_PKCS #1 v1.5 signature padding) */
  LTC_LTC_PKCS_1_EME    = 2         /* Block type 2 (LTC_PKCS #1 v1.5 encryption padding) */
};

enum ltc_pkcs_1_paddings
{
  LTC_LTC_PKCS_1_V1_5   = 1,        /* LTC_PKCS #1 v1.5 padding (\sa ltc_pkcs_1_v1_5_blocks) */
  LTC_LTC_PKCS_1_OAEP   = 2,        /* LTC_PKCS #1 v2.0 encryption padding */
  LTC_LTC_PKCS_1_PSS    = 3         /* LTC_PKCS #1 v2.1 signature padding */
};

int pkcs_1_mgf1(      int            hash_idx,
                const unsigned char *seed, unsigned long seedlen,
                      unsigned char *mask, unsigned long masklen);

int pkcs_1_i2osp(void *n, unsigned long modulus_len, unsigned char *out);
int pkcs_1_os2ip(void *n, unsigned char *in, unsigned long inlen);

/* *** v1.5 padding */
int pkcs_1_v1_5_encode(const unsigned char *msg, 
                             unsigned long  msglen,
                             int            block_type,
                             unsigned long  modulus_bitlen,
                             unsigned char *out, 
                             unsigned long *outlen);

int pkcs_1_v1_5_decode(const unsigned char *msg, 
                             unsigned long  msglen,
                                       int  block_type,
                             unsigned long  modulus_bitlen,
                             unsigned char *out, 
                             unsigned long *outlen,
                                       int *is_valid);

/* *** v2.1 padding */
int pkcs_1_oaep_encode(const unsigned char *msg,    unsigned long msglen,
                       const unsigned char *lparam, unsigned long lparamlen,
                             unsigned long modulus_bitlen, const struct algo_properties_st *hash,
                             unsigned char *out,    unsigned long *outlen);

int pkcs_1_oaep_decode(const unsigned char *msg,    unsigned long msglen,
                       const unsigned char *lparam, unsigned long lparamlen,
                             unsigned long modulus_bitlen, const struct algo_properties_st *hash,
                             unsigned char *out,    unsigned long *outlen,
                             int           *res);

int pkcs_1_pss_encode(const unsigned char *msghash, unsigned long msghashlen,
                            unsigned long saltlen, const struct algo_properties_st *hash,
                            unsigned long modulus_bitlen,
                            unsigned char *out,     unsigned long *outlen);

int pkcs_1_pss_decode(const unsigned char *msghash, unsigned long msghashlen,
                      const unsigned char *sig,     unsigned long siglen,
                            unsigned long saltlen,  int           hash_idx,
                            unsigned long modulus_bitlen, int    *res);

#endif /* LTC_PKCS_1 */

