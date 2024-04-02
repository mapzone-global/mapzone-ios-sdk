#import <Foundation/Foundation.h>

#import "MZGLFoundation.h"
#import "MZGLAnnotation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 `MZGLShape` is an abstract class that represents a shape or annotation. Shapes
 constitute the content of a map — not only the overlays atop the map, but also
 the content that forms the base map.

 Create instances of `MZGLPointAnnotation`, `MZGLPointCollection`, `MZGLPolyline`,
 `MGLMultiPolyline`, `MZGLPolygon`, `MGLMultiPolygon`, or `MZGLShapeCollection` in
 order to use `MZGLShape`'s methods. Do not create instances of `MZGLShape`
 directly, and do not create your own subclasses of this class. The shape
 classes correspond to the
 <a href="https://tools.ietf.org/html/rfc7946#section-3.1">Geometry</a> object
 types in the GeoJSON standard, but some have nonstandard names for backwards
 compatibility.

 Although you do not create instances of this class directly, you can use its
 `+[MZGLShape shapeWithData:encoding:error:]` factory method to create one of the
 concrete subclasses of `MZGLShape` noted above from GeoJSON data. To access a
 shape’s attributes, use the corresponding `MZGLFeature` class instead.

 You can add shapes to the map by adding them to an `MZGLShapeSource` object.
 Configure the appearance of an `MZGLShapeSource`’s or `MZGLVectorTileSource`’s
 shapes collectively using a concrete instance of `MZGLVectorStyleLayer`.
 Alternatively, you can add some kinds of shapes directly to a map view as
 annotations or overlays.
 
 You can filter the features in a `MZGLVectorStyleLayer` or vary their layout or
 paint attributes based on the features’ geographies. Pass an `MZGLShape` into an
 `NSPredicate` with the format `SELF IN %@` or `%@ CONTAINS SELF` and set the
 `MZGLVectorStyleLayer.predicate` property to that predicate, or set a layout or
 paint attribute to a similarly formatted `NSExpression`.
 */
MGL_EXPORT
@interface MZGLShape : NSObject <MZGLAnnotation, NSSecureCoding>

#pragma mark Creating a Shape

/**
 Returns an `MZGLShape` object initialized with the given data interpreted as a
 string containing a GeoJSON object.

 If the GeoJSON object is a geometry, the returned value is a kind of
 `MZGLShape`. If it is a feature object, the returned value is a kind of
 `MZGLShape` that conforms to the `MZGLFeature` protocol. If it is a feature
 collection object, the returned value is an instance of
 `MZGLShapeCollectionFeature`.

 ### Example

 ```swift
 let url = mainBundle.url(forResource: "amsterdam", withExtension: "geojson")!
 let data = try! Data(contentsOf: url)
 let feature = try! MZGLShape(data: data, encoding: String.Encoding.utf8.rawValue) as! MZGLShapeCollectionFeature
 ```

 @param data String data containing GeoJSON source code.
 @param encoding The encoding used by `data`.
 @param outError Upon return, if an error has occurred, a pointer to an
    `NSError` object describing the error. Pass in `NULL` to ignore any error.
 @return An `MZGLShape` object representation of `data`, or `nil` if `data` could
    not be parsed as valid GeoJSON source code. If `nil`, `outError` contains an
    `NSError` object describing the problem.
 */
+ (nullable MZGLShape *)shapeWithData:(NSData *)data encoding:(NSStringEncoding)encoding error:(NSError * _Nullable *)outError;

#pragma mark Accessing the Shape Attributes

/**
 The title of the shape annotation.

 The default value of this property is `nil`.

 This property is ignored when the shape is used in an `MZGLShapeSource`. To name
 a shape used in a shape source, create an `MZGLFeature` and add an attribute to
 the `MZGLFeature.attributes` property.
 */
@property (nonatomic, copy, nullable) NSString *title;

/**
 The subtitle of the shape annotation. The default value of this property is
 `nil`.

 This property is ignored when the shape is used in an `MZGLShapeSource`. To
 provide additional information about a shape used in a shape source, create an
 `MZGLFeature` and add an attribute to the `MZGLFeature.attributes` property.
 */
@property (nonatomic, copy, nullable) NSString *subtitle;

#if !TARGET_OS_IPHONE

/**
 The tooltip of the shape annotation.

 The default value of this property is `nil`.

 This property is ignored when the shape is used in an `MZGLShapeSource`.
 */
@property (nonatomic, copy, nullable) NSString *toolTip;

#endif

#pragma mark Creating GeoJSON Data

/**
 Returns the GeoJSON string representation of the shape encapsulated in a data
 object.

 @param encoding The string encoding to use.
 @return A data object containing the shape’s GeoJSON string representation.
 */
- (NSData *)geoJSONDataUsingEncoding:(NSStringEncoding)encoding;

@end

NS_ASSUME_NONNULL_END
