//
//  ViewController.m
//  dlSample1
//
//  Created by wizard on 6/8/17.
//  Copyright © 2017 wizard. All rights reserved.
//

#import "ViewController.h"
#import <deviceLog/deviceLog.h>
#import <CoreLocation/CoreLocation.h>


@interface ViewController ()

@end

@implementation ViewController

@synthesize logView;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void) viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [[deviceLog sharedInstance] attachTextView: logView               // The view for the deviceLog from the storyboard
                                         color:[UIColor blackColor]   // The background color for the deviceLog View
                                    anchorType:noAnchor ];       	  // No collapsing.
    
    [[deviceLog sharedInstance] clearStatus];
    [deviceLog sharedInstance].defaultColor = [UIColor greenColor];
    [[deviceLog sharedInstance] setButtonTextColor:[UIColor whiteColor]];
    [[deviceLog sharedInstance] logStatus:@"BEGIN!"];
    [[deviceLog sharedInstance] logStatus:@"Edit the file 'deviceLog.plist' in the 'deviceLog.bundle' to configure." withColor:[UIColor cyanColor]];
    [[deviceLog sharedInstance] logStatus:@"Look for details in the ReadMe file." withColor:[UIColor yellowColor]];
    [[deviceLog sharedInstance] logStatus:@"Touch screen with two fingers to bring up menu." withColor:[UIColor redColor]];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
