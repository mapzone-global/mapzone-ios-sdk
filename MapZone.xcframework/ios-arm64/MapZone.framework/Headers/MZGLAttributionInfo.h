#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>

#import "MZGLFoundation.h"
#import "MZGLTypes.h"

NS_ASSUME_NONNULL_BEGIN

/**
 The attribution info is represented in the longest format available.
 */
typedef NS_ENUM(NSUInteger, MZGLAttributionInfoStyle) {
    /**
     Specifies a short attribution info style.
     */
    MZGLAttributionInfoStyleShort = 1,
    /**
     Specifies a medium attribution info style.
     */
    MZGLAttributionInfoStyleMedium,
    /**
     Specifies a long attribution info style.
     */
    MZGLAttributionInfoStyleLong
};

/**
 Information about an attribution statement, usually a copyright or trademark
 statement, associated with a map content source.
 */
MGL_EXPORT
@interface MZGLAttributionInfo : NSObject

/**
 Returns an initialized attribution info object with the given title and URL.

 @param title The attribution statement’s title.
 @param URL A URL to more information about the entity named in the attribution.
 @return An initialized attribution info object.
 */
- (instancetype)initWithTitle:(NSAttributedString *)title URL:(nullable NSURL *)URL;

/**
 The attribution statement’s attributed title text.
 */
@property (nonatomic) NSAttributedString *title;

/**
 The URL to more information about the entity named in the attribution.

 If this property is set, the attribution statement should be displayed as a
 hyperlink or action button. Otherwise, if it is `nil`, the attribution
 statement should be displayed as plain text.
 */
@property (nonatomic, nullable) NSURL *URL;

/**
 A Boolean value indicating whether the attribution statement is a shortcut to a
 feedback tool.

 If this property is set, the statement should be treated as a way for the user
 to provide feedback rather than an attribution statement.
 */
@property (nonatomic, getter=isFeedbackLink) BOOL feedbackLink;

/**
 Returns a copy of the current `title` formatted accordingly to `style`.
 
 Example: If the `style` property is set to `MZGLAttributionInfoStyleShort` and the
 `title` property is set to `OpenStreetMap`, then this method returns `OSM`.
 
 @param style The attribution info style.
 
 @return The `NSAttributedString` styled title.
 */
- (NSAttributedString *)titleWithStyle:(MZGLAttributionInfoStyle)style;

@end

NS_ASSUME_NONNULL_END
