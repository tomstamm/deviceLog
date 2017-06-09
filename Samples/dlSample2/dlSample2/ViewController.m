//
//  ViewController.m
//  dlSample2
//
//  Created by wizard on 6/8/17.
//  Copyright © 2017 wizard. All rights reserved.
//

#import "ViewController.h"
#import <deviceLog/deviceLog.h>

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
    
    [[deviceLog sharedInstance] attachTextView: logView                 // The view for the deviceLog from the storyboard
                                         color:[UIColor colorWithRed:0.0 green:0.0 blue:0.0 alpha:0.7]
                                                                        // The background color for the deviceLog View
                                    anchorType:bottomAnchor ];          // Anchored the deviceLog to the bottom of the screen.
    
    [[deviceLog sharedInstance] clearStatus];
    [deviceLog sharedInstance].defaultColor = [UIColor greenColor];
    [[deviceLog sharedInstance] setButtonTextColor:[UIColor whiteColor]];
    [[deviceLog sharedInstance] logStatus:@"BEGIN!"];
    [[deviceLog sharedInstance] logStatus:@"Edit the file 'deviceLog.plist' in the 'deviceLog.bundle' to configure." withColor:[UIColor cyanColor]];
    [[deviceLog sharedInstance] logStatus:@"Look for details in the ReadMe file." withColor:[UIColor yellowColor]];
    [[deviceLog sharedInstance] logStatus:@"Touch screen with one finger to collapse the log view & touch the grey bar below to bring it back." withColor:[UIColor orangeColor]];
    [[deviceLog sharedInstance] logStatus:@"Touch screen with two fingers to bring up menu." withColor:[UIColor redColor]];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
