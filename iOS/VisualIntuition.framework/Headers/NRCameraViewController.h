//
//  NRCameraViewController.h
//  VisualIntuition
//
//  Created by Jakub on 02/08/16.
//  Copyright © 2016 NexRef. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^TrackerFound)(void);
typedef void (^ShareBlock)(UIViewController*);
typedef void (^TargetScanned)(NSString*, NSString*, NSString*);
typedef void (^CTAButtonTapped)(NSString*, NSString*, NSString*);
typedef void (^ScannerTitle)(NSString*, NSString*);

@protocol CustomFontDependant <NSObject>
- (void)fontChanged:(NSString*)fontName;
@end

@interface NRCameraViewController: UINavigationController

@property (nonatomic, copy) TargetScanned targetScannedBlock;
@property (nonatomic, copy) CTAButtonTapped ctaButtonTappedBlock;
@property (nonatomic, copy) ScannerTitle scannerTitleBlock;


+ (instancetype)instance:(TrackerFound)callback withShareBlock:(ShareBlock)shareBlock;
+ (instancetype)instanceForCampaign:(NSString*)campaignName withCallback:(TrackerFound)callback withShareBlock:(ShareBlock)shareBlock;
+ (void)downloadRemoteVideosForCampaign:(NSString*)campaignName;
+ (void)downloadRemoteVideosForApplication:(NSString*)bundleName fromApi:(NSString*)apiUrl;
- (void)changeFont:(NSString*)fontName;
@end
