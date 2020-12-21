/*
 @link: https://github.com/ideawu/Objective-C-RSA
 @link: https://github.com/Hstripe/RHRSAUtil
 */

#import <Foundation/Foundation.h>

@interface RSA : NSObject

#pragma mark - 加密
/******************** 加密 ********************/
/**
 公钥加密

 @param str     明文字符串
 @param pubKey  公钥(非safeUrlBase64的, 用safeUrlBase64Decode转)
 @return        base64 encoded string
 */
+ (NSString *)encryptString:(NSString *)str publicKey:(NSString *)pubKey;

/**
 公钥加密

 @param data    明文字符串的二进制流(UTF-8转码)
 @param pubKey  公钥(非safeUrlBase64的, 用safeUrlBase64Decode转)
 @return        raw data
 */
+ (NSData *)encryptData:(NSData *)data publicKey:(NSString *)pubKey;

/**
 私钥加密

 @param str     明文字符串
 @param privKey 私钥(非safeUrlBase64的, 用safeUrlBase64Decode转)
 @return        直接转换为safeURLBase64类型
 */
+ (NSString *)encryptString:(NSString *)str privateKey:(NSString *)privKey;

/**
 私钥加密

 @param data    明文字符串的二进制流(UTF-8转码)
 @param privKey 私钥(非safeUrlBase64的, 用safeUrlBase64Decode转)
 @return        raw data
 */
+ (NSData *)encryptData:(NSData *)data privateKey:(NSString *)privKey;

/**
 私钥加密
 
 @param obj     数组/字典
 @param privKey 私钥(非safeUrlBase64的, 用safeUrlBase64Decode转)
 @return        直接转换为safeURLBase64类型
 */
+ (NSString *)encryptObject:(id)obj privateKey:(NSString *)privKey;



#pragma mark - 解密
/******************** 解密 ********************/
// decrypt base64 encoded string, convert result to string(not base64 encoded)
/**
 公钥解密

 @param str     后台返回直接处理(可以为safeUrlBase64类型)
 @param pubKey  公钥(非safeUrlBase64的, 用safeUrlBase64Decode转)
 @return        加密数据的明文
 */
+ (NSString *)decryptString:(NSString *)str publicKey:(NSString *)pubKey;

/**
 公钥解密

 @param data    非base64编码
 @param pubKey  公钥(非safeUrlBase64的, 用safeUrlBase64Decode转)
 @return        加密数据的明文的二进制流
 */
+ (NSData *)decryptData:(NSData *)data publicKey:(NSString *)pubKey;

/**
 私钥解密

 @param str     后台返回 不能 直接处理(需用safeUrlBase64Decode转)
 @param privKey 私钥(非safeUrlBase64的, 用safeUrlBase64Decode转)
 @return        加密数据的明文
 */
+ (NSString *)decryptString:(NSString *)str privateKey:(NSString *)privKey;

/**
 私钥解密

 @param data    非base64编码
 @param privKey 私钥(非safeUrlBase64的, 用safeUrlBase64Decode转)
 @return        加密数据的明文的二进制流
 */
+ (NSData *)decryptData:(NSData *)data privateKey:(NSString *)privKey;

/**
 解密 (不常用)

 @param data    非base64编码
 @param keyRef  公钥或私钥
 @return        加密数据的明文的二进制流
 */
+ (NSData *)decryptData:(NSData *)data withKeyRef:(SecKeyRef) keyRef;




#pragma mark - 签名
/******************** 签名 ********************/

/**
 生成签名

 @param plainString     明文字符串
 @param privKey         私钥(非safeUrlBase64的, 用safeUrlBase64Decode转)
 @return                直接转换为safeUrlBase64
 */
+ (NSString *)rsaSignString:(NSString *)plainString WithPrivateKey:(NSString *)privKey;

/**
 生成签名
 
 @param obj             对象数组/字典
 @param privKey         私钥(非safeUrlBase64的, 用safeUrlBase64Decode转)
 @return                直接转换为safeUrlBase64
 */
+ (NSString *)rsaSignObj:(id)obj WithPrivateKey:(NSString *)privKey;

/**
 验证签名

 @param signature       后台返回的签名
 @param plainString     明文字符串
 @param pubKey          公钥(非safeUrlBase64的, 用safeUrlBase64Decode转)
 @return                是否验证通过
 */
+ (BOOL)rsaVerifySignature:(NSString *)signature plainString:(NSString *)plainString WithPublicKey:(NSString *)pubKey;


#pragma mark -

// safeUrlBase64 方法
// 将safe_url_base64解码到正常base64
+ (NSString *)safeUrlBase64Decode:(NSString *)safeUrlbase64Str;
// 将base64编码到为safe_url_base64
+ (NSString *)safeUrlBase64Encode:(NSString *)base64Str;

@end
