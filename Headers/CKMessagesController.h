//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UISplitViewController.h"

#import "CKTranscriptComposeDelegate.h"
#import "MFMailComposeViewControllerDelegate.h"
#import "UIActionSheetDelegate.h"
#import "UIAlertViewDelegate.h"
#import "UINavigationControllerDelegate.h"
#import "UISplitViewControllerDelegate.h"

@class CKConversation, CKConversationListController, CKNavigationController, CKTranscriptController, CKViewController, MFMailComposeViewController, NSMutableArray, NSSet, NSString;

@interface CKMessagesController : UISplitViewController <UISplitViewControllerDelegate, MFMailComposeViewControllerDelegate, UIActionSheetDelegate, CKTranscriptComposeDelegate, UINavigationControllerDelegate, UIAlertViewDelegate>
{
    MFMailComposeViewController *_mailComposeController;
    CKConversation *_currentConversation;
    NSMutableArray *_conversationCache;
    CDUnknownBlockType _alertViewHandler;
    unsigned int _attachmentPreviewQosClass;
    CKConversationListController *_conversationListController;
    CKTranscriptController *_transcriptController;
    CKTranscriptController *_composeTranscriptController;
    CKNavigationController *_conversationListNavigationController;
    CKNavigationController *_transcriptNavigationController;
    CKNavigationController *_composeTranscriptNavigationController;
    CKViewController *_blankViewController;
}

@property(retain, nonatomic) CKViewController *blankViewController; // @synthesize blankViewController=_blankViewController;
@property(retain, nonatomic) CKNavigationController *composeTranscriptNavigationController; // @synthesize composeTranscriptNavigationController=_composeTranscriptNavigationController;
@property(retain, nonatomic) CKNavigationController *transcriptNavigationController; // @synthesize transcriptNavigationController=_transcriptNavigationController;
@property(retain, nonatomic) CKNavigationController *conversationListNavigationController; // @synthesize conversationListNavigationController=_conversationListNavigationController;
@property(retain, nonatomic) CKTranscriptController *composeTranscriptController; // @synthesize composeTranscriptController=_composeTranscriptController;
@property(copy, nonatomic) CDUnknownBlockType alertViewHandler; // @synthesize alertViewHandler=_alertViewHandler;
@property(retain, nonatomic) CKConversation *currentConversation; // @synthesize currentConversation=_currentConversation;
@property(retain, nonatomic) CKTranscriptController *transcriptController; // @synthesize transcriptController=_transcriptController;
@property(retain, nonatomic) CKConversationListController *conversationListController; // @synthesize conversationListController=_conversationListController;
- (void)alertView:(id)arg1 didDismissWithButtonIndex:(long long)arg2;
- (void)mailComposeController:(id)arg1 didFinishWithResult:(int)arg2 error:(id)arg3;
- (void)showMailComposeSheetForAddress:(id)arg1;
@property(retain, nonatomic) id <NSCoding> autosaveIdentifier; // @dynamic autosaveIdentifier;
- (void)autosaveMailComposition;
- (void)showMailComposeSheetForAutosavedMessage;
- (void)_showMailComposeSheet;
- (_Bool)isShowingTranscriptWithUnsentText;
- (_Bool)showUnreadConversationsWithLastConversation:(id)arg1 ignoringMessages:(id)arg2;
- (_Bool)hasUnreadFilteredConversationsIgnoringMessages:(id)arg1;
- (_Bool)isShowingTranscriptController;
@property(readonly, nonatomic) _Bool isShowingConversationListController;
- (_Bool)isShowingDirtyComposeModalView;
- (_Bool)currentCompositionHasContent;
- (_Bool)isAnimatingMessageSend;
- (_Bool)isComposingMessage;
- (_Bool)isShowingBlankTranscript;
- (void)showConversationList:(_Bool)arg1;
- (_Bool)resumeToConversation:(id)arg1;
- (void)showConversationAndMessageForSearchURL:(id)arg1;
- (void)showConversationAndMessageForChatGUID:(id)arg1 messageGUID:(id)arg2 animate:(_Bool)arg3;
- (void)showConversation:(id)arg1 animate:(_Bool)arg2;
- (void)showConversation:(id)arg1 animate:(_Bool)arg2 forceToTranscript:(_Bool)arg3;
- (void)resetNewMessageCompositionRecipients;
- (void)cancelNewMessageComposition;
- (void)showNanoComposeWithRecipients:(id)arg1 composition:(id)arg2 animated:(_Bool)arg3;
- (void)showNewMessageCompositionPanelWithRecipients:(id)arg1 composition:(id)arg2 animated:(_Bool)arg3;
- (void)_appStateChange:(id)arg1;
- (void)_chatItemsDidChange:(id)arg1;
- (void)_chatRegistryDidLoad:(id)arg1;
- (void)_conversationLeft:(id)arg1;
- (void)_setIsShowingNoSelectionUI:(_Bool)arg1;
- (void)_popToConversationListAndPerformBlockAnimated:(_Bool)arg1 block:(CDUnknownBlockType)arg2;
- (void)_updateAlertSuppressionContext;
- (void)__updateAlertSuppressionContext;
@property(readonly, retain, nonatomic) NSSet *alertSuppressionContexts;
- (_Bool)_isShowingModalTranscript;
- (_Bool)_isShowingFullscreenController;
- (void)keyCommandCompose:(id)arg1;
- (void)_addConversationToCache:(id)arg1;
- (void)_pruneConversationCache;
- (void)_prepareToDumpCachedConversation:(id)arg1;
- (_Bool)_canDumpConversationFromCache:(id)arg1;
- (_Bool)splitViewController:(id)arg1 collapseSecondaryViewController:(id)arg2 ontoPrimaryViewController:(id)arg3;
- (void)navigationController:(id)arg1 didShowViewController:(id)arg2 animated:(_Bool)arg3;
- (void)navigationController:(id)arg1 willShowViewController:(id)arg2 animated:(_Bool)arg3;
- (void)showNewMessageCompositionForComposition:(id)arg1;
- (void)transcriptControllerDidReportSpam:(id)arg1;
- (void)transcriptController:(id)arg1 didSelectNewConversation:(id)arg2;
- (_Bool)supportsAttachments;
- (void)transcriptController:(id)arg1 didSendMessageInConversation:(id)arg2;
- (void)transcriptController:(id)arg1 willSendComposition:(id)arg2 inConversation:(id)arg3;
- (void)didCancelComposition:(id)arg1;
- (void)parentControllerDidBecomeActive;
- (void)parentControllerDidResume:(_Bool)arg1 animating:(_Bool)arg2;
- (void)prepareForResume;
- (void)prepareForSuspend;
- (void)performResumeDeferredSetup;
- (_Bool)becomeFirstResponder;
- (void)didReceiveMemoryWarning;
- (void)viewWillTransitionToSize:(struct CGSize)arg1 withTransitionCoordinator:(id)arg2;
- (_Bool)shouldAutorotate;
- (id)childViewControllerForStatusBarHidden;
- (void)viewDidDisappear:(_Bool)arg1;
- (void)viewDidLoad;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)loadView;
- (id)init;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

