//
//  ViewController.m
//  GW_TextView
//
//  Created by zdwx on 2019/7/19.
//  Copyright © 2019 DoubleK. All rights reserved.
//

#import "ViewController.h"
#import "GW_TextView.h"
@interface ViewController ()
@property (weak, nonatomic) IBOutlet GW_TextView *text2;
@property (strong ,nonatomic) GW_TextView *textV;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self test1];
}

- (void)test1{
    _textV = [[GW_TextView alloc] initWithFrame:CGRectMake(10, 100, self.view.bounds.size.width-20, 300)];
    [self.view addSubview:_textV];
    _textV.backgroundColor = [UIColor greenColor];
    _textV.placeholder = @"lihaile";
    _textV.maxLength = 10;
    
    _text2.placeholder = @"hhhhhhh";
    _text2.maxLength = 100;
    _text2.cornerRadius = 20;
    
    _textV.GWTextViewEditingBlock = ^(GW_TextViewEditingType editingType) {
        NSLog(@"GWTextViewEditingBlock = %ld",(long)editingType);
    };
    
    _textV.GWTextDidChangeBlock = ^(GW_TextView * _Nonnull textView, NSString * _Nonnull text) {
        NSLog(@"GWTextDidChangeBlock = %@",text);
    };
    
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    [self.view endEditing:YES];
}

@end
