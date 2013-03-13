//
//  Helper.m
//  Chattar
//
//  Created by kirill on 2/20/13.
//
//

#import "Helper.h"

@implementation Helper

+(BOOL)isStringCorrect:(NSString*)stringToCheck{
    NSCharacterSet *whitespace = [NSCharacterSet whitespaceAndNewlineCharacterSet];
    NSString *trimmed = [stringToCheck stringByTrimmingCharactersInSet:whitespace];
    if ([trimmed length] == 0) {
        return NO;
    }
    return YES;
}

+(NSArray*)sortArray:(NSArray*) array dependingOnField:(NSString*)fieldName inAscendingOrder:(BOOL)ascending{
    
    NSSortDescriptor* sortOrder = [NSSortDescriptor sortDescriptorWithKey:fieldName ascending:ascending];
    [array sortedArrayUsingDescriptors:[NSArray arrayWithObject:sortOrder]];
    
    return array;
}

+(BOOL)checkSymbol:(NSString *)symbol inString:(NSString *)string{
    NSCharacterSet* characterSet = [NSCharacterSet characterSetWithCharactersInString:symbol];
    if ([string rangeOfCharacterFromSet:characterSet].location == NSNotFound) {
        return NO;
    }
    return YES;
}

+(NSString*)createTitleFromXMPPTitle:(NSString*)xmppTitle{
    NSCharacterSet* characterSet = [NSCharacterSet characterSetWithCharactersInString:@"@"];
    return [[xmppTitle componentsSeparatedByCharactersInSet:characterSet] objectAtIndex:0];
}
@end