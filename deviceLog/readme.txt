The deviceLog.framework is a utility object to allow logging to a text view when an app is not attached to a
debugger.  It can be used a regular text view in an app with many features available.

    1)  It can be collapsible, using a defined layout constraint.
    2)  It can handle color text.
    3)  It has a text file storage mechanism.  Text files can be save for later: view and shared.
    4)  This object is self-contained it just needs a view and optionally a constraint to work.
    5)  This object is a singleton, after it is initialized it can be called from anywhere.
    6)  If the deviceLog view is has a constraint initialized, it can be collapsed by a single-tap gesture in the
        view and a single-tap on the bar at the edge of the screen will un-collapse it.
    7) A two-finger tap gesture will bring up a menu to manipulate the text.

Add the following files to your project:
	deviceLog.framework
	deviceLog.bundle
Make these two files dependancies to your app in the "Build Phases"

Inside the deviceLog.bundle is:
    	Andale Mono.ttf     	(My preferred truetype mono spaced font.  You don't HAVE to use it.)
    	device.xcassets     	(A directory of images used for controls in the deviceLog object.)
	deviceLog.plist		(Easy access configuration)

The "Andale Mono.ttf" is not a standard font in IOS, To install it:
    In your app's project plist. add the following entry as an array, "Fonts provided by application" and add the name
    of the font into the first item of the array.  You must include the bundle path to the font so enter the string "deviceLog.bundle/Andale Mono.ttf".  
    If you want to add other fonts to your project, you would do that here.

Hooking up for app views to the deviceLog object:
    In your storyboard, Add an empty view to hold your deviceLog view and add the instance reference to your view controller's .h file.
    Then in your view controller call the attachTextView method in the deviceLog object.

Example 1 (Collapsible deviceLog):
    - (void) viewWillAppear:(BOOL)animated {
        [[deviceLog sharedInstance] attachTextView: deviceLogView               // The view for the deviceLog from the storyboard
                                              color: [UIColor colorWithRed:0.0 green:0.0 blue:0.0 alpha:0.3] // The background color for the deviceLog View
                                        anchorType: leftAnchor ];               // Collapse the constraint toward the left.

        [[deviceLog sharedInstance] clearStatus];
        [deviceLog sharedInstance].defaultColor = [UIColor greenColor];
        [[deviceLog sharedInstance] setButtonTextColor:[UIColor whiteColor]];
        [[deviceLog sharedInstance] logStatus:@"BEGIN!"];
    }


Example 2 (Non-collapsible deviceLog):
    - (void) viewWillAppear:(BOOL)animated {
        [[deviceLog sharedInstance] attachTextView: deviceLogView               // The view for the deviceLog from the storyboard
                                             color:[UIColor blackColor]         // The background color for the deviceLog View
                                        anchorType:noAnchor ];       	            // No collapsing.

        [[deviceLog sharedInstance] clearStatus];
        [deviceLog sharedInstance].defaultColor = [UIColor greenColor];
        [[deviceLog sharedInstance] setButtonTextColor:[UIColor whiteColor]];
        [[deviceLog sharedInstance] logStatus:@"BEGIN!"];
    }

After the deviceLog is initialize it's singleton object can be called from anywhere in your app.

See the deviceLog.h file for method reference.

Some of the deviceLogs initial preferences can be overridden by the file deviceLog.plist.  The values are:
	newOnTop		Boolean	YES = New messages are added to the top of the text view.
					NO = New messages are added to the bottom of the text view.
	liveScrollToNew		Boolean	YES = Scroll to new content automatically when it is Added.
					NO = Only scroll when the user performs a scroll action.
	showTime		Boolean	YES = Add a timestamp in front of the message.
					NO = No timestamp.
	copyTo_NSLog		Boolean	YES = Messages are echoed to NSLog.
					NO = Messages are not echoed to NSLog.
	verboseWarnings		Boolean	YES = Complain overtime you attempt to log a message if the deviceLog is not initialized.
					NO = Fail Silently.
	clearBufferAfterSave	Boolean	YES = Clear the display after you save text.
					NO = Leave the display after you save text.
	controlPaneActive	Boolean	YES = On two-finger tap, bring up function menu ("Timestamp", "Clear", "Save", "Open In…", "List", "Cancel").
					NO =  On two-finger tap, do nothing.
	timestampControlActive	Boolean	YES = Show "Timestamp" in function menu.
					NO = Hide "Timestamp" in function menu.
	clearControlActive	Boolean	YES = Show "Clear" button in function menu. 
					NO = Hide "Clear" button in function menu.
	saveControlActive	Boolean	YES = Show "Save" button in function menu. 
					NO = Hide "Save" button in function menu.
	openInControlActive	Boolean	YES = Show "Open In…" button in function menu. 
					NO = Hide "Open In…" button in function menu.
	listControlActive	Boolean	YES = Show "List" button in function menu. 
					NO = Hide "List" button in function menu.
	cancelControlActive	Boolean	YES = Show "Cancel" button in function menu. 
					NO = Hide "Cancel" button in function menu.
	font			String		Initial font family (default is "AndaleMono").
	fontSize		Number		Initial font size (default is 18.0).

