//
//  UIApplication+LM.h
//  LMCategory
//
//  Created by 李蒙 on 15/7/29.
//  Copyright (c) 2015年 李蒙. All rights reserved.
//

#import <UIKit/UIKit.h>

#define LMCallTelephone(tel) [[UIApplication sharedApplication] lm_callTelephone:tel]
#define LMOpenAppStoreDetails(identifier) [[UIApplication sharedApplication] lm_openAppDetailsURLForIdentifier:identifier]
#define LMOpenAppStoreReviews(identifier) [[UIApplication sharedApplication] lm_openAppReviewsURLForIdentifier:identifier]
#define LMOpenAppForURLSchemes(schemes) [[UIApplication sharedApplication] lm_openAppForURLSchemes:schemes]

#define LMAlertShowGrantedAccessDenied(type, alertTitle, cancelTitle) [[UIApplication sharedApplication] lm_showGrantedAccessDeniedWithType:type title:alertTitle cancelButtonTitle:cancelTitle]


#define LMAlertShowGrantedAccessDeniedCalendar(alertTitle, cancelTitle) LMAlertShowGrantedAccessDenied(@"日历", alertTitle, cancelTitle)
#define LMAlertShowGrantedAccessDeniedContacts(alertTitle, cancelTitle) LMAlertShowGrantedAccessDenied(@"通讯录", alertTitle, cancelTitle)
#define LMAlertShowGrantedAccessDeniedMicrophone(alertTitle, cancelTitle) LMAlertShowGrantedAccessDenied(@"麦克风", alertTitle, cancelTitle)
#define LMAlertShowGrantedAccessDeniedCamera(alertTitle, cancelTitle) LMAlertShowGrantedAccessDenied(@"相机", alertTitle, cancelTitle)
#define LMAlertShowGrantedAccessDeniedPhotos(alertTitle, cancelTitle) LMAlertShowGrantedAccessDenied(@"照片", alertTitle, cancelTitle)
#define LMAlertShowGrantedAccessDeniedReminders(alertTitle, cancelTitle) LMAlertShowGrantedAccessDenied(@"提醒事项", alertTitle, cancelTitle)
#define LMAlertShowGrantedAccessDeniedLocation(alertTitle, cancelTitle) LMAlertShowGrantedAccessDenied(@"定位服务", alertTitle, cancelTitle)

@interface UIApplication (LM)

/**
 *  是否首次打开这个应用
 *
 *  @param block 是/不是
 */
- (void)lm_firstOpenedApp:(void (^)(BOOL isFirstOpened))block;

/**
 *  是否首次打开这个build
 *
 *  @param block 是/不是
 */
- (void)lm_firstOpenedBuild:(void (^)(BOOL isFirstOpened))block;

/**
 *  是否首次打开这个Version
 *
 *  @param block 是/不是
 */
- (void)lm_firstOpenedVersion:(void (^)(BOOL isFirstOpened))block;

/**
 *  是否首次打开
 *
 *  @param key   key
 *  @param block 是/不是
 */
- (void)lm_firstOpenedKey:(NSString *)key flag:(void (^)(BOOL isFirstOpened))block;

/**
 *  请求Calendar权限
 *
 *  @param accessGranted 授权成功
 *  @param accessDenied  授权失败
 */
- (void)lm_requestAccessGrantedToCalendarWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;

/**
 *  请求Contacts权限
 *
 *  @param accessGranted 授权成功
 *  @param accessDenied  授权失败
 */
- (void)lm_requestAccessGrantedToContactsWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;

/**
 *  请求Microphone权限
 *
 *  @param accessGranted 授权成功
 *  @param accessDenied  授权失败
 */
- (void)lm_requestAccessGrantedToMicrophoneWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;

/**
 *  请求Camera权限
 *
 *  @param accessGranted 授权成功
 *  @param accessDenied  授权失败
 */
- (void)lm_requestAccessGrantedToCameraWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;
/**
 *  请求Photos权限
 *
 *  @param accessGranted 授权成功
 *  @param accessDenied  授权失败
 */
- (void)lm_requestAccessGrantedToPhotosWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;

/**
 *  请求Reminders权限
 *
 *  @param accessGranted 授权成功
 *  @param accessDenied  授权失败
 */
- (void)lm_requestAccessGrantedToRemindersWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;

/**
 *  请求Motion权限(授权失败也可以用)
 *
 *  @param accessGranted 授权成功
 */
- (void)lm_requestAccessGrantedToMotionWithSuccess:(void(^)())accessGranted;

/**
 *  请求Location权限(iOS8需要在Info.plist添加NSLocationWhenInUseUsageDescription)
 *
 *  获取断授权状态[CLLocationManager authorizationStatus]
 *  kCLAuthorizationStatusNotDetermined -> 第一次授权
 *  kCLAuthorizationStatusAuthorizedWhenInUse、kCLAuthorizationStatusAuthorizedAlways -> 已授权
 *  kCLAuthorizationStatusDenied -> 拒绝授权
 *
 *  @param accessGranted 授权成功
 *  @param accessDenied  授权失败
 */
- (void)lm_requestAccessGrantedToLocationWithSuccess:(void(^)())accessGranted andFailure:(void(^)())accessDenied;

/**
 *  授权失败提醒
 *
 *  @param type              授权类型(e.g.通讯录)
 *  @param title             title
 *  @param cancelButtonTitle cancelButtonTitle
 */
- (void)lm_showGrantedAccessDeniedWithType:(NSString *)type title:(NSString *)title cancelButtonTitle:(NSString *)cancelButtonTitle;

/**
 *  调用定位获取GPS坐标(CLLocation)
 *
 *  @param didUpdateLocations 成功回调
 */
- (void)lm_locationDidUpdate:(void (^)(NSArray *locations, NSError *error))didUpdateLocations;

/**
 *  打电话
 *
 *  @param tel 电话号码
 *
 *  @return 是否拨打成功
 */
- (BOOL)lm_callTelephone:(NSString *)tel;

/**
 *  跳转到appStroe应用详情
 *
 *  @param identifier 应用identifier
 *
 *  @return 是否跳转成功
 */
- (BOOL)lm_openAppDetailsURLForIdentifier:(NSUInteger)identifier;

/**
 *  跳转到appStroe应用评论
 *
 *  @param identifier 应用identifier
 *
 *  @return 是否跳转成功
 */
- (BOOL)lm_openAppReviewsURLForIdentifier:(NSUInteger)identifier;

/**
 *  跳转到App
 *
 *  @param schemes URLSchemes
 *
 *  @return 是否跳转成功
 */
- (BOOL)lm_openAppForURLSchemes:(NSString *)schemes;

@end
