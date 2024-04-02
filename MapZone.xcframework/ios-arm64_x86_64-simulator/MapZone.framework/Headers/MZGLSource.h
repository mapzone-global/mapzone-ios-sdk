#import <Foundation/Foundation.h>

#import "MZGLFoundation.h"
#import "MZGLTypes.h"

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN MGL_EXPORT MGLExceptionName const MGLInvalidStyleSourceException;

/**
 `MZGLSource` is an abstract base class for map content sources. A map content
 source supplies content to be shown on the map. A source is added to an
 `MZGLStyle` object along with an `MZGLForegroundStyleLayer` object. The
 foreground style layer defines the appearance of any content supplied by the
 source.

 Each source defined by the style JSON file is represented at runtime by an
 `MZGLSource` object that you can use to refine the map’s content. You can also
 add and remove sources dynamically using methods such as
 `-[MZGLStyle addSource:]` and `-[MZGLStyle sourceWithIdentifier:]`.

 Create instances of `MZGLShapeSource`, `MZGLComputedShapeSource`,
 `MZGLImageSource`, and the concrete subclasses of `MZGLTileSource`
 (`MZGLVectorTileSource` and `MZGLRasterTileSource`) in order to use `MZGLSource`’s
 properties and methods. Do not create instances of `MZGLSource` directly, and do
 not create your own subclasses of this class.
 */
MGL_EXPORT
@interface MZGLSource : NSObject

#pragma mark Initializing a Source

- (instancetype)init __attribute__((unavailable("Use -initWithIdentifier: instead.")));

/**
 Returns a source initialized with an identifier.

 After initializing and configuring the source, add it to a map view’s style
 using the `-[MZGLStyle addSource:]` method.

 @param identifier A string that uniquely identifies the source in the style to
    which it is added.
 @return An initialized source.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier;

#pragma mark Identifying a Source

/**
 A string that uniquely identifies the source in the style to which it is added.
 */
@property (nonatomic, copy) NSString *identifier;

@end

NS_ASSUME_NONNULL_END
