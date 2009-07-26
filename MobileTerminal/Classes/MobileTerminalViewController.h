// MobileTerminalViewController.h
// MobileTerminal

#import <UIKit/UIKit.h>

@class TerminalGroupView;
@class TerminalKeyboard;

// Protocol to get notified about when the preferences button is pressed.
// TOOD(allen): We should find a better way to do this.
@protocol MobileTerminalInterfaceDelegate
@required
- (void)preferencesButtonPressed;
@end

@interface MobileTerminalViewController : UIViewController {
@private
  UIView* contentView;
  TerminalGroupView* terminalGroupView;
  UIPageControl* terminalSelector;
  TerminalKeyboard* terminalKeyboard;
  BOOL shouldShowKeyboard;
  // If the keyboard is actually shown right now (not if it should be shown)
  BOOL keyboardShown;
  UIButton* preferencesButton;
  UIButton* menuButton;
  id<MobileTerminalInterfaceDelegate> interfaceDelegate;
}

@property (nonatomic, retain) IBOutlet UIView* contentView;
@property (nonatomic, retain) IBOutlet TerminalGroupView* terminalGroupView;
@property (nonatomic, retain) IBOutlet UIPageControl* terminalSelector;
@property (nonatomic, retain) IBOutlet UIButton* preferencesButton;
@property (nonatomic, retain) IBOutlet UIButton* menuButton;
@property (nonatomic, retain) IBOutlet id<MobileTerminalInterfaceDelegate> interfaceDelegate;

- (void)terminalSelectionDidChange:(id)sender;
- (void)preferencesButtonPressed:(id)sender;
- (void)menuButtonPressed:(id)sender;

@end
