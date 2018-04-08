//
//  ViewController.m
//  IPOrInt
//
//  Created by OuYang on 2018/4/8.
//  Copyright © 2018年 OuYang. All rights reserved.
//

#import "ViewController.h"

#import "ipForInt.h"

@interface ViewController ()

@property (weak, nonatomic) IBOutlet UITextField *textField;

@property (weak, nonatomic) IBOutlet UILabel *label;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    /// 如果需要代码 这个方法够用了 不需要在看确认方法
    /*
    NSString *ipStr = @"211.150.233.8";
    const char *charIPStr;
    
    charIPStr = [ipStr UTF8String];
    int ipInt = ip_str2int(charIPStr);
    
    char test[32] = {'a','b','c','d'};
    unsigned int ipNumber = 3549882632;
    
    char *data = ip_int2str(ipNumber,test);
    NSString *ipStr1 = [[NSString alloc] initWithUTF8String:data];
    
    NSLog(@"____%ld__%@",ipInt,ipStr1);
     */
}


#pragma mark - 确认方法
- (IBAction)subitmAction:(id)sender {

    // 简单处理

    NSString *str = self.textField.text;
    
    if (str.length < 8) {
        return;
    }
    
    if ([str containsString:@"."]) {
        
        //NSString *ipStr = @"211.150.233.8";
        const char *charIPStr;
        charIPStr = [str UTF8String];
        int ipInt = ip_str2int(charIPStr);
        
        /// 注意使用%ld 长整型
        self.label.text = [[NSString alloc]initWithFormat:@"ip:%@=%ld",str,ipInt];
        
    } else {
        
        char test[32] = {'a','b','c','d'};
        unsigned int ipNumber = [self.textField.text longLongValue];
        
        char *data = ip_int2str(ipNumber,test);
        NSString *ipStr1 = [[NSString alloc] initWithUTF8String:data];
        self.label.text = [[NSString alloc]initWithFormat:@"ip:%@=%ld",ipStr1,ipNumber];
    }
    
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
