
#import <UIKit/UIKit.h>

@class RootViewController;

@interface AppController : NSObject < UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController	*viewController;
    
    UIAlertView *loadingView;
}
@property (nonatomic, readonly) RootViewController *viewController;
- (void)loadingDidComplete;
- (void)showCustomFullscreenAd;

@end

