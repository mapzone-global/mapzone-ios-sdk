#import <Foundation/Foundation.h>

#import "MZGLFoundation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 The `MZGLDefaultStyle` defines the predefined vendor style
 */
MGL_EXPORT
@interface MZGLDefaultStyle : NSObject

/**
The style URL
 */
@property (nonatomic,retain) NSURL* url;

/**
The style name
 */
@property (nonatomic,retain) NSString* name;

/**
The style version
 */
@property (nonatomic) int version;

@end

NS_ASSUME_NONNULL_END
