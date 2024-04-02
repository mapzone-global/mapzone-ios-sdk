#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <QuartzCore/QuartzCore.h>

#import "MZGLFoundation.h"
#import "MZGLStyleValue.h"
#import "MZGLStyleLayer.h"
#import "MZGLGeometry.h"

NS_ASSUME_NONNULL_BEGIN

@class MZGLMapView;
@class MZGLStyle;

typedef struct MZGLStyleLayerDrawingContext {
    CGSize size;
    CLLocationCoordinate2D centerCoordinate;
    double zoomLevel;
    CLLocationDirection direction;
    CGFloat pitch;
    CGFloat fieldOfView;
    MGLMatrix4 projectionMatrix;
} MZGLStyleLayerDrawingContext;

MGL_EXPORT
@interface MZGLOpenGLStyleLayer : MZGLStyleLayer

@property (nonatomic, weak, readonly) MZGLStyle *style;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#if TARGET_OS_IPHONE
@property (nonatomic, readonly) EAGLContext *context;
#else
@property (nonatomic, readonly) CGLContextObj context;
#endif
#pragma clang diagnostic pop

- (instancetype)initWithIdentifier:(NSString *)identifier;

- (void)didMoveToMapView:(MZGLMapView *)mapView;

- (void)willMoveFromMapView:(MZGLMapView *)mapView;

- (void)drawInMapView:(MZGLMapView *)mapView withContext:(MZGLStyleLayerDrawingContext)context;

- (void)setNeedsDisplay;

@end

NS_ASSUME_NONNULL_END
