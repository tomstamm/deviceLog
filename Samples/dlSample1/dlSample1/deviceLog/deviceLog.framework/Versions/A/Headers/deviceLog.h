//
//  deviceLog.h
//  geoLab
//
//  Created by Tom Stamm on 5/13/15.
//  Copyright (c) 2015 TomStamm. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#ifndef NS_ENUM
@import Foundation;
#endif
typedef NS_ENUM(unsigned int, deviceLogAnchorType) {
    /** deviceLog does not collapse.  There is no anchor. */
    noAnchor=0,
    /** Anchored the deviceLog to the left of the screen */
    leftAnchor,
    /** Anchored the deviceLog to the bottom of the screen */
    bottomAnchor,
    /** Anchored the deviceLog to the right of the screen */
    rightAnchor,
    /** Anchored the deviceLog to the top of the screen */
    topAnchor
};


/**
 @abstract The deviceLog object is a utility object to allow logging to a text view when an app is not attached to a
        debugger.  It can be used a regular text view in an app with many features available.

        1) It can be collapsible, using a anchor specification.

        2) It can handle color text.

        3) It has a text file storage mechanism.  Text files can be save for later: view and shared.

        4) This object is self-contained it just needs a view to work.

        5) This object is a singleton, after it is initialized it can be called from anywhere.

        6) If the deviceLog view is not specified as noAnchor, it can be collapsed by a single-tap gesture in the
            view and a single-tap on the bar at the edge of the screen will un-collapse it.

        7) A two-finger tap gesture will bring up a menu to manupulate the text.
 */
@interface deviceLog : NSObject<UIDocumentInteractionControllerDelegate, UITableViewDelegate, UITableViewDataSource>

/** Font used to display text */
@property (strong, nonatomic)   UIFont  *font;
/** The default color for text is no color is specified */
@property (strong, nonatomic)   UIColor *defaultColor;
/** The background color for text menu, brought up by a two-finger tap */
@property (strong, nonatomic)   UIColor *controlColor;
/** The button text color for text menu, brought up by a two-finger tap */
@property (strong, nonatomic)   UIColor *buttonTextColor;

/**
 @abstract This method is the singleton shared instance for the deviceLog object.

 Example Usage:
 @code
 - (void) viewWillAppear:(BOOL)animated {
    [[deviceLog sharedInstance] attachTextView:deviceLogView
                                         color:[UIColor colorWithRed:0.0 green:0.0 blue:0.0 alpha:0.3]
                                    anchorType:leftAnchor ];

    [self willAnimateRotationToInterfaceOrientation:self.interfaceOrientation duration:0];
    [[deviceLog sharedInstance] clearStatus];
 }
 @endcode
 @return The shared instance of the deviceLog object.
 */
+ (deviceLog *)sharedInstance;

/**
 @abstract This method is the singleton shared instance for the deviceLog object.

 Example Usage:
 @code
 [[deviceLog sharedInstance] attachTextView:reportTxt
                                      color:[UIColor blackColor]
                                 anchorType:bottomAnchor ];
 [[deviceLog sharedInstance] clearStatus];
 [deviceLog sharedInstance].defaultColor = [UIColor greenColor];
 [[deviceLog sharedInstance] setButtonTextColor:[UIColor whiteColor]];
 [[deviceLog sharedInstance] logStatus:@"BEGIN!"];
 @endcode
 @param view
        This is the view to build the deviceLog into.
 @param bkColor
        User defined background color for the deviceLog view. If nil the default color will be white.
 @param anchor
        Parameter @c anchor is type "deviceLogAnchorType", and can have the value noAnchor, leftAnchor,
        bottomAnchor, rightAnchor or topAnchor. This parameter is used when collapsing and un-collapsing 
        the deviceLog view.
 */
-(void) attachTextView:(UIView *)view color:(UIColor *)bkColor anchorType:(deviceLogAnchorType)anchor;

/**
 @abstract The default color for the control buttons text labels is 'white'.  This method allows you to change
 it with another UIColor spec.

 Example Usage:
 @code
 [[deviceLog sharedInstance] setButtonTextColor:[UIColor grayColor]];
 @endcode
 @param textColor
        UIColor spec for the view in the deviceLog object that holds the control buttons ('Clear', 'Save',
        'Open In...', 'List', 'Cancel').
 */
-(void) setButtonTextColor:(UIColor *)textColor;

/**
 @abstract The default color for the control buttons is 'white(alpha=0.3)'.  This method allows you to change
        it with another UIColor spec.

 Example Usage:
 @code
 [[deviceLog sharedInstance] setControlColor:[UIColor whiteColor]];
 @endcode
 @param cColor
        UIColor spec for the view in the deviceLog object that holds the control buttons ('Clear', 'Save',
        'Open In...', 'List', 'Cancel').
 */
-(void) setControlColor:(UIColor *)cColor;

/**
 @abstract The default font is 'AndaleMono 18.0'.  This method allows you to change it.  If the specified
        font cannot be found, the deviceLog object will print a message through NSLog and substitute a 
        standard IOS system font (Courier/18.0).

 Example Usage:
 @code
 [[deviceLog sharedInstance] changeFont:@"Helvetica" size:16.0];
 @endcode
 @param name
        String that hold the name of the new font.  The font must be a standard IOS system font or a
        font installed into the app.
 @param size
        Size of the new font.
 */
-(void) changeFont:(NSString *)name size:(float)size;

/**
 @abstract Clear all text out of the deviceLog object.

 Example Usage:
 @code
 [[deviceLog sharedInstance] clearStatus];
 @endcode
 */
-(void) clearStatus;


/**
 @abstract Post a timestamp into the deviceLog object in the default color.

 Example Usage:
 @code
 [[deviceLog sharedInstance] logTimestamp];
 @endcode
 */
-(void) logTimestamp;


/**
 @abstract Write a string to the deviceLog view in the default color.

 Example Usage:
 @code
 [[deviceLog sharedInstance] logStatus:@"Begin the report."];
 @endcode
 @param message
        An NSString value to write to the deviceLog view.
 */
-(void) logStatus:(NSString *)message;

/**
 @abstract Write a string to the deviceLog view in the defined color.

 Example Usage:
 @code
 [[deviceLog sharedInstance] logStatus:@"Begin the report." withColor:[UIColor redColor]];
 @endcode
 @param message
        An NSString value to write to the deviceLog view.
 @param color
        An UIColor value for the text.
 */
-(void) logStatus:(NSString *)message withColor:(UIColor *)color;

/**
 @abstract Write a atrributed string to the deviceLog view.

 Example Usage:
 @code
 NSDictionary *attrs = @{ NSForegroundColorAttributeName: color,
 NSFontAttributeName: font};
 NSAttributedString *attrStr = [[NSAttributedString alloc] initWithString:message attributes:attrs];

 [self logAttStatus:attrStr];
 @endcode
 @param message
        An NSAttributedString value to write to the deviceLog view.
 */
-(void) logAttStatus:(NSAttributedString *)message;

/**
 @abstract Replace the text in the deviceLog view with a string in the default color.

 Example Usage:
 @code
 [[deviceLog sharedInstance] assignStatus:@"Start over now!"];
 @endcode
 @param message
        An NSString value to write to the deviceLog view.
 */
-(void) assignStatus:(NSString *)message;

/**
 @abstract Replace the text in the deviceLog view with a string in the defined color.

 Example Usage:
 @code
 [[deviceLog sharedInstance] assignStatus:@"Start over now!" withColor:[UIColor blueColor]];
 @endcode
 @param message
        An NSString value to write to the deviceLog view.
 @param color
        An UIColor value for the text.
 */
-(void) assignStatus:(NSString *)message withColor:(UIColor *)color;

/**
 @abstract A convenience method to write the values of a rectangle(CGRect) to the deviceLog view in
        the defined color.

 Example Usage:
 @code
 CGRect frame = titleLbl.bounds;
 [[deviceLog sharedInstance] logRect:frame name:@"frame" color:[UIColor redColor]];
 @endcode
 @param rect
        An CGRect value to write to the deviceLog view.
 @param name
        An string to name a rectangle value.
 @param color
        An UIColor value for the text.
 */
-(void) logRect:(CGRect)rect name:(NSString *)name withColor:(UIColor *) color;

/**
 @abstract A convenience method to write the description of an object to the deviceLog view in
 the defined color.

 Example Usage:
 @code
 NSString string = @"test";
 [[deviceLog sharedInstance] string name:@"string" color:[UIColor redColor]];
 @endcode
 @param object
 An object description to write to the deviceLog view.
 @param name
 An string to name an object.
 @param color
 An UIColor value for the text.
 */
-(void) logObject:(id)object name:(NSString *)name withColor:(UIColor *)color;

@end
