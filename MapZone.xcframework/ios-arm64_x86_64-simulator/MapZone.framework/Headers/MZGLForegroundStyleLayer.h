#import <Foundation/Foundation.h>

#import "MZGLFoundation.h"
#import "MZGLStyleLayer.h"

NS_ASSUME_NONNULL_BEGIN

@class MZGLSource;

/**
 `MZGLForegroundStyleLayer` is an abstract superclass for style layers whose
 content is defined by an `MZGLSource` object.

 Create instances of `MZGLRasterStyleLayer`, `MZGLHillshadeStyleLayer`, and the
 concrete subclasses of `MZGLVectorStyleLayer` in order to use
 `MZGLForegroundStyleLayer`'s methods. Do not create instances of
 `MZGLForegroundStyleLayer` directly, and do not create your own subclasses of
 this class.
 */
MGL_EXPORT
@interface MZGLForegroundStyleLayer : MZGLStyleLayer

#pragma mark Initializing a Style Layer

- (instancetype)init __attribute__((unavailable("Use -init methods of concrete subclasses instead.")));

#pragma mark Specifying a Style Layer’s Content

/**
 Identifier of the source from which the receiver obtains the data to style.
 */
@property (nonatomic, readonly, nullable) NSString *sourceIdentifier;

@end

NS_ASSUME_NONNULL_END
