#import <ChatKit/ChatKit.h>
#import "Languages.h"

#define IS_IOS_7_0 [list respondsToSelector:@selector(deleteConversationAtIndex:)]
#define IS_IOS_8_0 [list respondsToSelector:@selector(deleteConversationsAtIndexes:)]
#define IS_IOS_8_4 [list respondsToSelector:@selector(deleteConversation:)]

%hook CKConversationListController
- (void)setEditing:(BOOL)editing animated:(BOOL)animated {
	%orig;
	
	/***************************
	*      SETUP LANGUAGE      *
	****************************/
	/* CHECK System language */
	NSString *system_lang = [NSLocale preferredLanguages][0];
	
	/* Set Button Title */ 
	if ([delete_btn_langs.allKeys containsObject:(NSString *)system_lang])
		button_title = delete_btn_langs[(NSString *)system_lang];
	/* Set ActionSheet Title */
	if ([delete_uis_title_langs.allKeys containsObject:(NSString *)system_lang])
		delete_uis_title = delete_uis_title_langs[(NSString *)system_lang];
	/* Set ActionSheet CancelButton Title */
	if ([delete_uis_btn_cancel_langs.allKeys containsObject:(NSString *)system_lang])
		delete_uis_btn_cancel = delete_uis_btn_cancel_langs[(NSString *)system_lang];
	/* Set ActionSheet DestructiveButton Title */
	if ([delete_uis_btn_dest_langs.allKeys containsObject:(NSString *)system_lang])
		delete_uis_btn_dest = delete_uis_btn_dest_langs[(NSString *)system_lang];
	
	if (editing) {
		UIBarButtonItem *deleteAll = [[UIBarButtonItem alloc] initWithTitle:(NSString *)button_title style:UIBarButtonItemStylePlain target:self action:@selector(deleteAll:)];
		self.navigationItem.rightBarButtonItem = deleteAll;
		[deleteAll release];
	} else {
		UIBarButtonItem *compose = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemCompose target:self action:@selector(composeButtonClicked:)];
		self.navigationItem.rightBarButtonItem = compose;
		[compose release];
	}
}

%new
- (void)deleteAll:(id)sender {
	UIActionSheet *actionSheet = [[UIActionSheet alloc]
		initWithTitle:(NSString *)delete_uis_title
		delegate:(id<UIActionSheetDelegate>)self
		cancelButtonTitle:(NSString *)delete_uis_btn_cancel
		destructiveButtonTitle:(NSString *)delete_uis_btn_dest
		otherButtonTitles:nil, nil];
	
	[actionSheet showInView:self.view];
	[actionSheet release];
}

%new
-(void)actionSheet:(UIActionSheet*)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex {
	if (buttonIndex == 0) {
		CKConversationList *list = MSHookIvar<CKConversationList *>(self, "_conversationList");
		UITableView *messages = MSHookIvar<UITableView *>(self, "_table");
		NSUInteger msgCount = [(CKTranscriptBubbleData *)[list conversations] count];
		if (msgCount > 0) {
			if (IS_IOS_8_0) {
				[list deleteConversationsAtIndexes:[NSIndexSet indexSetWithIndexesInRange:NSMakeRange(0, msgCount)]];
			} else if (IS_IOS_7_0) {
				while (msgCount) {
					[list deleteConversationAtIndex:(msgCount - 1)];
					msgCount--;
				}
			} else if (IS_IOS_8_4) {
				[list deleteConversations:[list conversations]];
			}
		}
		[self setEditing:NO animated:NO];
		[messages reloadData];
	}
}
%end

