/* magic sizes */
#define MD4_SIZE 16
#define MD5_SIZE 16

char *crypt_des(const char *pw, const char *salt);
char *crypt_md5(const char *pw, const char *salt);
char *crypt_nthash(const char *pw, const char *salt);
char *crypt_blowfish(const char *pw, const char *salt);
char *crypt_sha256 (const char *pw, const char *salt);
char *crypt_sha512 (const char *pw, const char *salt);

extern void _crypt_to64(char *s, u_long v, int n);
extern void b64_from_24bit(uint8_t B2, uint8_t B1, uint8_t B0, int n, int *buflen, char **cp);
