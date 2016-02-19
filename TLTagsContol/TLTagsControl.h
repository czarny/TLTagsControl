//
//  TLTagsControl.h
//  TagsInputSample
//
//  Created by Антон Кузнецов on 11.02.15.
//  Copyright (c) 2015 TheLightPrjg. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TLTagsControl;

@protocol TLTagsControlDelegate <NSObject>

- (void)tagsControl:(TLTagsControl *)tagsControl tappedAtIndex:(NSInteger)index;
- (void)tagsControl:(TLTagsControl *)tagsControl didAddTag:(NSString*)tag;
- (void)tagsControl:(TLTagsControl *)tagsControl didDeleteTag:(NSString*)tag;

@end

typedef NS_ENUM(NSUInteger, TLTagsControlMode) {
    TLTagsControlModeEdit,
    TLTagsControlModeList,
};

@interface TLTagsControl : UIScrollView

@property (nonatomic, strong) NSMutableArray *tags;
@property (nonatomic, strong) UIFont *tagsFont;
@property (nonatomic, strong) UIColor *tagsBackgroundColor;
@property (nonatomic, strong) UIColor *tagsTextColor;
@property (nonatomic, strong) UIColor *tagsDeleteButtonColor;
@property (nonatomic, strong) NSAttributedString *tagPlaceholder;
@property (nonatomic) TLTagsControlMode mode;

@property (nonatomic, weak) id<TLTagsControlDelegate> tagDelegate;

- (id)initWithFrame:(CGRect)frame andTags:(NSArray *)tags withTagsControlMode:(TLTagsControlMode)mode;

- (void)addTag:(NSString *)tag;
- (void)reloadTagSubviews;

@end