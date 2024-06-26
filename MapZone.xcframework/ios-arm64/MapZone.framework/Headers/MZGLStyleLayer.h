#import <Foundation/Foundation.h>

#import "MZGLFoundation.h"
#import "MZGLTypes.h"

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN MGL_EXPORT MGLExceptionName const MGLInvalidStyleLayerException;

/**
 `MZGLStyleLayer` is an abstract base class for style layers. A style layer
 manages the layout and appearance of content at a specific z-index in a style.
 An `MZGLStyle` object consists of one or more `MZGLStyleLayer` objects.

 Each style layer defined by the style JSON file is represented at runtime by an
 `MZGLStyleLayer` object, which you can use to refine the map’s appearance. You
 can also add and remove style layers dynamically.

 Create instances of `MZGLBackgroundStyleLayer` and the concrete subclasses of
 `MZGLForegroundStyleLayer` in order to use `MZGLStyleLayer`'s properties and methods.
 You do not create instances of `MZGLStyleLayer` directly, and do not
 create your own subclasses of this class.
 
 Do not add `MZGLStyleLayer` objects to the `style` property of a `MZGLMapView` before
 `-mapView:didFinishLoadingStyle:` is called.
 */
MGL_EXPORT
@interface MZGLStyleLayer : NSObject

#pragma mark Initializing a Style Layer

- (instancetype)init __attribute__((unavailable("Use -init methods of concrete subclasses instead.")));

#pragma mark Identifying a Style Layer

/**
 A string that uniquely identifies the style layer in the style to which it is
 added.
 */
@property (nonatomic, copy, readonly) NSString *identifier;

#pragma mark Configuring a Style Layer’s Visibility

/**
 Whether this layer is displayed. A value of `NO` hides the layer.
 
 #### Related examples
 See the <a href="https://docs.mapbox.com/ios/maps/examples/runtime-toggle-layer/">
 Show and hide a layer</a> example to learn how to toggle an `MZGLStyleLayer`
 object's visibility.
 */
@property (nonatomic, assign, getter=isVisible) BOOL visible;

/**
 The maximum zoom level at which the layer gets parsed and appears. This value is a floating-point number.
 */
@property (nonatomic, assign) float maximumZoomLevel;

/**
 The minimum zoom level at which the layer gets parsed and appears. This value is a floating-point number.
 */
@property (nonatomic, assign) float minimumZoomLevel;

@end

NS_ASSUME_NONNULL_END
