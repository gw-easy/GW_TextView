//
//  GW_TextView.h
//  GW_TextView
//
//  Created by zdwx on 2019/7/19.
//  Copyright © 2019 DoubleK. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, GW_TextViewEditingType) {
    GW_TextViewNone = 0,
    GW_TextViewBeginEditing, //开始编辑
    GW_TextViewEndEditing, //结束编辑
    GW_TextViewReturn, //return事件
};

@class GWTextView;

IB_DESIGNABLE
//IB_DESIGNABLE 效果就是带有IBInspectable自定义属性能再XIB上及时看到当前类调改的效果,比如设置placeholder的时候或者设置圆角,可以立即呈现.如果报错，请将这句话注释并重启


@interface GWTextView : UITextView

/// 获取编辑类型
@property (copy, nonatomic) void(^GWTextViewEditingBlock)(GW_TextViewEditingType editingType);

/**
 设定文本改变Block回调.
 */
@property (copy, nonatomic) void(^GWTextDidChangeBlock)(GWTextView *textView,NSString *text);

/**
 设定达到最大长度Block回调.
 */
@property (copy, nonatomic) void(^GWTextLengthDidMaxBlock)(GWTextView *textView,NSInteger maxLength);


/**
 便利构造器.
 */
+ (GWTextView *)textView;


//IBInspectable 将代码属性插入到xib或sb的状态栏里面

/**
 最大限制文本长度, 默认无限制, 如果被设为 0 也同样表示不限制字符数. -优先级高于maxLine
 */
@property (nonatomic, assign) IBInspectable NSUInteger maxLength;


/// 最大行数限制，默认无限制, 如果被设为 0 也同样表示不限制行数
@property (nonatomic, assign) IBInspectable NSUInteger maxLine;

/// 最大行数-省略号位置
@property (assign, nonatomic) IBInspectable NSLineBreakMode maxLineMode;

/**
 圆角半径.
 */
@property (nonatomic, assign) IBInspectable CGFloat cornerRadius;

/**
 边框宽度.
 */
@property (nonatomic, assign) IBInspectable CGFloat borderWidth;

/**
 边框颜色.
 */
@property (nonatomic, strong) IBInspectable UIColor *borderColor;

///< placeholderLabel
@property (nonatomic, strong) UILabel *placeholderLabel;
/**
 placeholder, 会自适应TextView宽高以及横竖屏切换, 字体默认和TextView一致.
 */
@property (nonatomic, copy)   IBInspectable NSString *placeholder;

/**
 placeholder文本颜色, 默认为#C7C7CD.
 */
@property (nonatomic, strong) IBInspectable UIColor *placeholderColor;

/**
 placeholder文本字体, 默认为UITextView的默认字体.
 */
@property (nonatomic, strong) UIFont *placeholderFont;

/**
 是否允许长按弹出UIMenuController, 默认为YES.
 */
@property (nonatomic, assign, getter=isCanPerformAction) BOOL canPerformAction;

/**
 该属性返回一个经过处理的 `self.text` 的值, 去除了首位的空格和换行.
 */
@property (nonatomic, readonly) NSString *formatText;
@end

NS_ASSUME_NONNULL_END
