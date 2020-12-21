//
//  JPSecurityUtility.m
//  JPCertificationKit
//
//  Created by Damon Gao on 2018/8/9.
//  Copyright © 2018年 Damon. All rights reserved.
//

#import "JPSecurityUtility.h"
#import "JPSDKManagerConfig.h"
#import "RSA.h"

@implementation JPSecurityUtility

+ (instancetype)shareInstance {
    static JPSecurityUtility *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if (_instance == nil) {
            _instance = [[self alloc] init];
            _instance.publicKey = [RSA safeUrlBase64Decode:pubKey];
            _instance.privateKey = [RSA safeUrlBase64Decode:priKey];
        }
    });
    return _instance;
}

/**
 校验公私钥是否失效 (赋值失败)
 */
- (BOOL)verifyKey {
    return [self.publicKey length] > 0 && [self.privateKey length] > 0;
}


/**
 重试 获取公私钥 (公私钥获取失败的情况)
 */
- (BOOL)retryAssigningKey {
    self.publicKey = [RSA safeUrlBase64Decode:pubKey];
    self.privateKey = [RSA safeUrlBase64Decode:priKey];
    return [self verifyKey];
}


/** 加密字符串/对象 */
+ (NSString *)encryptFromObj:(id)obj {
    if ([obj isKindOfClass:[NSString class]]) {
        return [RSA encryptString:(NSString *)obj privateKey:[JPSecurityUtility shareInstance].privateKey];
    } else {
        return [RSA encryptObject:obj privateKey:[JPSecurityUtility shareInstance].privateKey];
    }
}


/** 签名字符串/对象 */
+ (NSString *)signFromObj:(id)obj {
    if ([obj isKindOfClass:[NSString class]]) {
        return [RSA rsaSignString:(NSString *)obj WithPrivateKey:[JPSecurityUtility shareInstance].privateKey];
    } else {
        return [RSA rsaSignObj:obj WithPrivateKey:[JPSecurityUtility shareInstance].privateKey];
    }
}


/** 处理返回的加密数据 */
+ (NSString *)handleResultDecryptStr:(NSString *)str {
    return [RSA decryptString:str publicKey:[JPSecurityUtility shareInstance].publicKey];
}


@end
