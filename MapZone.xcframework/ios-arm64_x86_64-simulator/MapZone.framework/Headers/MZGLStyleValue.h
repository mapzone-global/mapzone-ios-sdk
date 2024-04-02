#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

#import "MZGLFoundation.h"
#import "MZGLTypes.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString *MZGLStyleFunctionOption NS_STRING_ENUM NS_UNAVAILABLE;

FOUNDATION_EXTERN MGL_EXPORT const MZGLStyleFunctionOption MZGLStyleFunctionOptionInterpolationBase __attribute__((unavailable("Use NSExpression instead, applying the mgl_interpolate:withCurveType:parameters:stops: function with a curve type of “exponential” and a non-nil parameter.")));

FOUNDATION_EXTERN MGL_EXPORT const MZGLStyleFunctionOption MZGLStyleFunctionOptionDefaultValue __attribute__((unavailable("Use +[NSExpression expressionForConditional:trueExpression:falseExpression:] instead.")));

typedef NS_ENUM(NSUInteger, MGLInterpolationMode) {
    MGLInterpolationModeExponential __attribute__((unavailable("Use NSExpression instead, applying the mgl_interpolate:withCurveType:parameters:stops: function with a curve type of “exponential”."))) = 0,
    MGLInterpolationModeInterval __attribute__((unavailable("Use NSExpression instead, calling the mgl_step:from:stops: function."))),
    MGLInterpolationModeCategorical __attribute__((unavailable("Use NSExpression instead."))),
    MGLInterpolationModeIdentity __attribute__((unavailable("Use +[NSExpression expressionForKeyPath:] instead.")))
} __attribute__((unavailable("Use NSExpression instead.")));

MGL_EXPORT __attribute__((unavailable("Use NSExpression instead.")))
@interface MZGLStyleValue<T> : NSObject
@end

MGL_EXPORT __attribute__((unavailable("Use +[NSExpression expressionForConstantValue:] instead.")))
@interface MGLConstantStyleValue<T> : MZGLStyleValue<T>
@end

@compatibility_alias MZGLStyleConstantValue MGLConstantStyleValue;

MGL_EXPORT __attribute__((unavailable("Use NSExpression instead, calling the mgl_step:from:stops: or mgl_interpolate:withCurveType:parameters:stops: function.")))
@interface MZGLStyleFunction<T> : MZGLStyleValue<T>
@end

MGL_EXPORT __attribute__((unavailable("Use NSExpression instead, applying the mgl_step:from:stops: or mgl_interpolate:withCurveType:parameters:stops: function to the $zoomLevel variable.")))
@interface MGLCameraStyleFunction<T> : MZGLStyleFunction<T>
@end

MGL_EXPORT __attribute__((unavailable("Use NSExpression instead, applying the mgl_step:from:stops: or mgl_interpolate:withCurveType:parameters:stops: function to a key path expression.")))
@interface MZGLSourceStyleFunction<T> : MZGLStyleFunction<T>
@end

MGL_EXPORT __attribute__((unavailable("Use a NSExpression instead with nested mgl_step:from:stops: or mgl_interpolate:withCurveType:parameters:stops: function calls.")))
@interface MGLCompositeStyleFunction<T> : MZGLStyleFunction<T>
@end

NS_ASSUME_NONNULL_END
