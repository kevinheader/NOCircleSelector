//
//  NOSELCircleSelector.h
//  NOCircleSelector
//
//  Created by Natalia Osiecka on 30.9.2014.
//  Copyright (c) 2014 iOskApps. All rights reserved.
//

#import <UIKit/UIKit.h>
// Views
#import "NOSELCircleDot.h"
// Models
#import "NOSELCircleDotConnection.h"

@class NOSELCircleSelector;

@protocol NOSELCircleSelectorDelegate <NSObject>

@optional

/**
 *  Called when dots array gets changed. Update the dots properties here. You can also set the order of dots on the view (bringSubviewToFront: etc).
 *
 *  @param circleSelector Current circleSelector instance.
 *  @param dots           Array of new dots.
 */
- (void)circleSelector:(NOSELCircleSelector *)circleSelector changedDots:(NSArray *)dots;

/**
 *  Called when dot connections array gets changed. Update the dot connections properties here.
 *
 *  @param circleSelector Current circleSelector instance.
 *  @param dotConnections Array of new dot connections.
 */
- (void)circleSelector:(NOSELCircleSelector *)circleSelector changedDotConnections:(NSArray *)dotConnections;

/**
 *  Called when a dot gets updated. Check the dot.angle to know the new value between <dot.minAngle, dot.maxAngle>;
 *
 *  @param circleSelector Current circleSelector instance.
 *  @param dot            Changed dot.
 */
- (void)circleSelector:(NOSELCircleSelector *)circleSelector updatedDot:(NOSELCircleDot *)dot;

/**
 *  Called when a dot started to move.
 *
 *  @param circleSelector Current circleSelector instance.
 *  @param dot            Updated dot.
 */
- (void)circleSelector:(NOSELCircleSelector *)circleSelector beganUpdatingDotPosition:(NOSELCircleDot *)dot;

/**
 *  Called when a dot ended to move.
 *
 *  @param circleSelector Current circleSelector instance.
 *  @param dot            Updated dot.
 */
- (void)circleSelector:(NOSELCircleSelector *)circleSelector endedUpdatingDotPosition:(NOSELCircleDot *)dot;

/**
 *  Allows to quickly swap base class of dot. Feel free to subclass NOCircleDot and pass it here.
 *
 *  @param circleSelector Current circleSelector instance.
 *  @return Subclass of NOCircleDot, which will be propagated to given controls.
 */
- (Class)circleSelectorRequestsNOCircleDotClass:(NOSELCircleSelector *)circleSelector;

@end

/**
 *  View displaying a circle at origin == middle and radius of MIN(width, height)/2 - pinRadius.
 */
@interface NOSELCircleSelector : UIView

/**
 *  Subscribe to get event handlers.
 */
@property (nonatomic, weak) id<NOSELCircleSelectorDelegate> delegate;

/**
 *  Determines the size (radius) of dot. Default 10.
 */
@property (nonatomic) CGFloat dotRadius;

/**
 *  Determines the width of selector line. Default 1.
 */
@property (nonatomic) CGFloat lineWidth;

/**
 *  Determines the color of selector line. Default redColor.
 */
@property (nonatomic) UIColor *lineColor;

/**
 *  Determines the color of selector insides. Default clearColor.
 */
@property (nonatomic) UIColor *fillColor;

/**
 *  Determines number of movable and non-movable dots. Changing the value will change dots array. Default 0.
 */
@property (nonatomic) NSInteger numberOfDots;

/**
 *  Allows quick access to each dot. Readwrite but override only when you really know what you're doing.
 */
@property (nonatomic) NSArray *dots;

/**
 *  Allows quick access to each dot connection. Readwrite but override only when you really know what you're doing.
 */
@property (nonatomic) NSArray *dotConnections;

/**
 *  Allow or forbit to jump between max and min value on touch. Default YES.
 */
@property (nonatomic) BOOL allowsCycling;

/**
 *  If more than 0, shadow on the circle is drawn. Default 0.
 */
@property (nonatomic) NSUInteger shadowWidth;

/**
 *  You need to set shadowWidth to > 0 to see the shadow. Color of the shadow. Default blackColor.
 */
@property (nonatomic) UIColor *shadowColor;

/**
 *  Public common initializer. Override and don't forget to call super.
 */
- (void)commonInit;

@end
