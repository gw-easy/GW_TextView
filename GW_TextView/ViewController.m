//
//  ViewController.m
//  GW_TextView
//
//  Created by zdwx on 2019/7/19.
//  Copyright © 2019 DoubleK. All rights reserved.
//

#import "ViewController.h"
#import "GWTextView.h"
@interface ViewController ()
@property (weak, nonatomic) IBOutlet GWTextView *text2;
@property (strong ,nonatomic) GWTextView *textV;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self test1];
}

- (void)test1{
    _textV = [[GWTextView alloc] initWithFrame:CGRectMake(10, 100, self.view.bounds.size.width-20, 50)];
    [self.view addSubview:_textV];
    _textV.backgroundColor = [UIColor greenColor];
    _textV.textColor = [UIColor blackColor];
    _textV.placeholder = @"lihaile";
//    _textV.maxLength = 10;
    _textV.font = [UIFont systemFontOfSize:25];
    _textV.textAlignment = NSTextAlignmentRight;
    
//    _textV.maxLine = 1;
//    _textV.maxLineMode = NSLineBreakByTruncatingTail;
    
    _text2.placeholder = @"hhhhhhh";
    _text2.maxLength = 100;
    
    _textV.GWTextViewEditingBlock = ^(GW_TextViewEditingType editingType) {
        NSLog(@"GWTextViewEditingBlock = %ld",(long)editingType);
    };
    
    _textV.GWTextDidChangeBlock = ^(GWTextView * _Nonnull textView, NSString * _Nonnull text) {
        NSLog(@"GWTextDidChangeBlock = %@",text);
    };
    
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    [self.view endEditing:YES];
}

@end
