//
//  AppDelegate.h
//  GW_TextView
//
//  Created by zdwx on 2019/7/19.
//  Copyright © 2019 DoubleK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

