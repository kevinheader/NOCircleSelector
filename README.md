[![Version](https://cocoapod-badges.herokuapp.com/v/NOCircleSelector/badge.png)](http://cocoadocs.org/docsets/NOCircleSelector) 
[![Platform](https://cocoapod-badges.herokuapp.com/p/NOCircleSelector/badge.png)](http://cocoadocs.org/docsets/NOCircleSelector) 

<p align="center" ><img src="https://raw.github.com/natalia-osa/NOCircleSelector/master/ReadmeImages/Demo.gif" alt="NOCircleSelector" title="NOCircleSelector" height="568"></p>

Circle shaped control to select given number of values.

## Structure:
There are three kinds of objects: 
- NOCircleSelector, which is an UIView and represents the whole area where the control is drawn. MIN(selector.width, selector.height) / 2 is the radius of selector.
- NOCircleDot, which is an UIView and represents the single dot. The size and all properties can be changed via properties. Don't forget about normal UIView properties. The control is easy to subclass so you can easily add custom views. To access it use delegate methods or dots array of NOCircleSelector.
- NOCircleDotConnection - a model class, representing the line between two NOCircleDot. You can customise it via properties. To access it use delegate methods or dotConnections array of NOCircleSelector.
The recommended method to differ the dot is to use NS_ENUM and set tags of these.

## Customisable:
#### In NOCircleSelector (+ all UIView properties like backgroundColor etc):
- numberOfDots
```objective-c
[_circleSelector setNumberOfDots:4];
```
- dotRadius
```objective-c
[_circleSelector setDotRadius:50.f];
```
- lineWidth - sets defaults in NOCircleDotConnection
```objective-c
[_circleSelector setLineWidth::2.f];
```
- lineColor - sets defaults in NOCircleDotConnection
```objective-c
[_circleSelector setLineColor:[UIColor redColor]];
```
- fillColor
```objective-c
[_circleSelector setFillColor:[UIColor blueColor]];
```

#### In NOCircleDot (+ all UIView properties like backgroundColor etc):
- lineWidth
```objective-c
[dot setLineWidth:2.f];
```
- lineColor
```objective-c
[dot setLineColor:[UIColor redColor]];
```
- fillColor
```objective-c
[dot setFillColor:[UIColor greenColor]];
```
- textLabel
```objective-c
[dot.textLabel setText@"Hello!"];
```
- imageView
```objective-c
[dot.imageView setImage:[UIImage imageNamed:@"girl"]];
```
- angle - degrees, represents current angle of dot in selector
```objective-c
[dot setAngle:90.f];
```
- minAngle - degrees, represents non crossable minimum range of dot in selector. Default 0.
```objective-c
[dot setMinAngle:0.f];
```
- maxAngle - degrees, represents non crossable maximum range of dot in selector. Default 360.
```objective-c
[dot setMaxAngle:360.f];
```

#### In NOCircleDotConnection:
- startDot - set automatically, do not overload if not required. Describes the first dot of connection.
- endDot - set automatically, do not overload if not required. Describes the second dot of connection.
- connectionColor
```objective-c
[connection setConnectionColor:[UIColor redColor]];
```
- lineWidth
```objective-c
[connection setLineWidth:3.f];
```
- dotConnectionBeetweenTag1:tag2: - convenience method to compare whether 2 dots are connected.
```objective-c
[dot setLineWidth:2.f];
```

## Installation:
#### Installation with CocoaPods
[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries.
```ruby
pod "NOCircleSelector", "~> 0.4"
```
#### Submodule
In your projects git folder type:
```bash
git submodule init
git submodule add --copy link to the repo--
git submodule update
```
Copy all files from NOCircleSelector folder.
#### Just download & attach
This is strongly misadvised as you won't be able to see code updates. Clone or download the source, copy all files from NOCircleSelector folder.

## Implementation:
Clone and see the demo for more examples about implementation. You can add the view via Storyboard or using code:
```objective-c
// in your view.h download the library
#import <NOCircleSelector/NOCircleSelector.h>
// add a property
@property (nonatomic, strong) NOCircleSelector *circleSelector;

// alloc & init the view or setup this via storyboard (eg in view's initWithFrame:)
_circleSelector = [[NOCircleSelector alloc] initWithFrame:frame];
[_circleSelector setBackgroundColor:[UIColor clearColor]];
[self addSubview:_circleSelector];
// update the frame (eg in view's layoutSubviews) or use constraints
[_circleSelector setFrame:self.bounds];

// in your controller setup basic view
- (void)viewDidLoad {
    [super viewDidLoad];
    
    // if you need you can subscribe to delegate to handle events
    [_aView.circleSelector setDelegate:self];
    [_aView.circleSelector setTag:ExampleCircleSelectorBig];
    [_aView.circleSelector setNumberOfDots:3];
    [_aView.circleSelector setDotRadius:30.f];
}

// and handle whichever delegate you need
- (void)circleSelector:(NOCircleSelector *)circleSelector changedDots:(NSArray *)dots {
    NOCircleDot *dot1 = [dots objectAtIndex:0];
    [dot1 setUserInteractionEnabled:NO];
    [dot1 setAngle:270.f];
	[dot1.imageView setImage:[UIImage imageNamed:@"girl"]];
}
- (void)circleSelector:(NOCircleSelector *)circleSelector changedDotConnections:(NSArray *)dotConnections {
    for (NOCircleDotConnection *dotConnection in dotConnections) {
        [dotConnection setConnectionColor:[UIColor blueColor]];
        [dotConnection setLineWidth:2.f];
    }
}
- (void)circleSelector:(NOCircleSelector *)circleSelector updatedDot:(NOCircleDot *)dot {
    [dot.textLabel setText:[NSString stringWithFormat:@"%d", (int)dot.angle]];
}
- (void)circleSelector:(NOCircleSelector *)circleSelector beganUpdatingDotPosition:(NOCircleDot *)dot {
    [_view.valueLabel setHidden:NO];
}
- (void)circleSelector:(NOCircleSelector *)circleSelector endedUpdatingDotPosition:(NOCircleDot *)dot {
    [_view.valueLabel setHidden:YES];
}
- (Class)circleSelectorRequestsNOCircleDotClass:(NOCircleSelector *)circleSelector {
    return [ExampleCircleDot class];
}
```

## Demo

Contains 2 examples. The first one (on the left) is simple < 20 lines configuration. The second one handles minimum and maximum values, line colors, widths etc.

<p align="center" ><img src="https://raw.github.com/natalia-osa/NOCircleSelector/master/ReadmeImages/EasyDemo.png" alt="NOCircleSelector" title="NOCircleSelector" height="568">   <img src="https://raw.github.com/natalia-osa/NOCircleSelector/master/ReadmeImages/CustomizedDemo.png" alt="NOCircleSelector" title="NOCircleSelector" height="568"></p>

## ChangeLog
- 0.4 Added method to get value from angle and rewritten method to get angle from value so it takes upon consideration minimum angle + minimum value.
- 0.3 Fixed issue with NSInteger valueForDot - now using CGFloat for more precision. Added fast method to swap basic class of NOCircleDot (delegate).
- 0.2 Fixed overlapping views stealing touch, min/max angle bug, added option to add images to each dot.
- 0.1 Basic version - Multiple selectors, models, touch handlers, logic.

## Author

Natalia Osiecka, osiecka.n@gmail.com
Natalia Osiecka MobileSoftware

## License

Available under the Apache 2.0 license. See the LICENSE file for more info.

## Requirements

Requires Xcode 6, targeting either iOS 5.0 or higher.
