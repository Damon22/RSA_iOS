//
//  JPSecurityUtility.h
//  JPCertificationKit
//
//  Created by Damon Gao on 2018/8/9.
//  Copyright © 2018年 Damon. All rights reserved.
//
//  安全组件 (加解密)

#import <Foundation/Foundation.h>

@interface JPSecurityUtility : NSObject

+ (instancetype)shareInstance;

@property (nonatomic, strong) NSString *publicKey;
@property (nonatomic, strong) NSString *privateKey;

/**
 校验公私钥是否失效 (赋值失败)
 */
- (BOOL)verifyKey;


/**
 重试 获取公私钥 (公私钥获取失败的情况)
 */
- (BOOL)retryAssigningKey;


/**
 加密字符串/对象
 */
+ (NSString *)encryptFromObj:(id)obj;


/**
 签名字符串/对象
 */
+ (NSString *)signFromObj:(id)obj;


/**
 处理返回的加密数据
 */
+ (NSString *)handleResultDecryptStr:(NSString *)str;

@end
