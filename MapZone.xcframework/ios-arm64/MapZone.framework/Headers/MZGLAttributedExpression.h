#import "MZGLFoundation.h"

NS_ASSUME_NONNULL_BEGIN

/** Options for `MZGLAttributedExpression.attributes`. */
typedef NSString * MZGLAttributedExpressionKey NS_TYPED_ENUM;

/** The font name string array expression used to format the text. */
FOUNDATION_EXTERN MGL_EXPORT MZGLAttributedExpressionKey const MGLFontNamesAttribute;

/** The font scale number expression relative to `MZGLSymbolStyleLayer.textFontSize` used to format the text. */
FOUNDATION_EXTERN MGL_EXPORT MZGLAttributedExpressionKey const MGLFontScaleAttribute;

/** The font color expression used to format the text. */
FOUNDATION_EXTERN MGL_EXPORT MZGLAttributedExpressionKey const MGLFontColorAttribute;

/**
 An `MZGLAttributedExpression` object associates text formatting attibutes (such as font size or
 font names) to an `NSExpression`.
 
 ### Example
 ```swift
 let redColor = UIColor.red
 let expression = NSExpression(forConstantValue: "Foo")
 let attributes: [MZGLAttributedExpressionKey: NSExpression] = [.fontNamesAttribute : NSExpression(forConstantValue: ["DIN Offc Pro Italic",
                                                                                                                     "Arial Unicode MS Regular"]),
                                                               .fontScaleAttribute: NSExpression(forConstantValue: 1.2),
                                                               .fontColorAttribute: NSExpression(forConstantValue: redColor)]
 let attributedExpression = MZGLAttributedExpression(expression, attributes:attributes)
 ```
 
 */
MGL_EXPORT
@interface MZGLAttributedExpression : NSObject

/**
 The expression content of the receiver as `NSExpression`.
 */
@property (strong, nonatomic) NSExpression *expression;

#if TARGET_OS_IPHONE
/**
 The formatting attributes dictionary.
 Key | Value Type
 --- | ---
 `MGLFontNamesAttribute` | An `NSExpression` evaluating to an `NSString` array.
 `MGLFontScaleAttribute` | An `NSExpression` evaluating to an `NSNumber` value.
 `MGLFontColorAttribute` | An `NSExpression` evaluating to an `UIColor`.

 */
@property (strong, nonatomic, readonly) NSDictionary<MZGLAttributedExpressionKey, NSExpression *> *attributes;
#else
/**
 The formatting attributes dictionary.
 Key | Value Type
 --- | ---
 `MGLFontNamesAttribute` | An `NSExpression` evaluating to an `NSString` array.
 `MGLFontScaleAttribute` | An `NSExpression` evaluating to an `NSNumber` value.
 `MGLFontColorAttribute` | An `NSExpression` evaluating to an `NSColor` on macos.
 */
@property (strong, nonatomic, readonly) NSDictionary<MZGLAttributedExpressionKey, NSExpression *> *attributes;
#endif


/**
 Returns an `MZGLAttributedExpression` object initialized with an expression and no attribute information.
 */
- (instancetype)initWithExpression:(NSExpression *)expression;

/** 
 Returns an `MZGLAttributedExpression` object initialized with an expression and text format attributes.
 */
- (instancetype)initWithExpression:(NSExpression *)expression attributes:(nonnull NSDictionary <MZGLAttributedExpressionKey, NSExpression *> *)attrs;

/**
 Creates an `MZGLAttributedExpression` object initialized with an expression and the format attributes for font names and font size.
 */
+ (instancetype)attributedExpression:(NSExpression *)expression fontNames:(nullable NSArray<NSString*> *)fontNames fontScale:(nullable NSNumber *)fontScale;

/**
 Creates an `MZGLAttributedExpression` object initialized with an expression and the format attributes dictionary.
 */
+ (instancetype)attributedExpression:(NSExpression *)expression attributes:(nonnull NSDictionary <MZGLAttributedExpressionKey, NSExpression *> *)attrs;

@end

NS_ASSUME_NONNULL_END
