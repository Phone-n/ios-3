//
//  OwnTracksAppDelegate.h
//  OwnTracks
//
//  Created by Christoph Krey on 03.02.14.
//  Copyright (c) 2014 OwnTracks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "Connection.h"
#import "Location+Create.h"
#import "Settings.h"

@protocol RangingDelegate <NSObject>

- (void)didDetermineState:(CLRegionState)state forRegion:(CLRegion *)region;
- (void)didRangeBeacons:(NSArray *)beacons inRegion:(CLBeaconRegion *)region;

@end

@interface OwnTracksAppDelegate : UIResponder <UIApplicationDelegate, CLLocationManagerDelegate, ConnectionDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (weak, nonatomic) id<RangingDelegate> delegate;
@property (strong, nonatomic) CLLocationManager *manager;
@property (nonatomic) int monitoring;
@property (nonatomic) BOOL ranging;
@property (strong, nonatomic) Connection *connection;
@property (strong, nonatomic) Settings *settings;

- (void)sendNow;
- (void)sendWayPoint:(Location *)location;
- (void)sendEmpty:(Friend *)friend;
- (void)reconnect;
- (void)connectionOff;
- (void)saveContext;

@end
