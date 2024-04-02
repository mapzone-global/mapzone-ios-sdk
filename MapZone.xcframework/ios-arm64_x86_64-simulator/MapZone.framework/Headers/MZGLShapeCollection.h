#import <Foundation/Foundation.h>

#import "MZGLFoundation.h"
#import "MZGLShape.h"

#import "MZGLTypes.h"

NS_ASSUME_NONNULL_BEGIN

/**
 An `MZGLShapeCollection` object represents a shape consisting of zero or more
 distinct but related shapes that are instances of `MZGLShape`. The constituent
 shapes can be a mixture of different kinds of shapes.

 `MZGLShapeCollection` is most commonly used to add multiple shapes to a single
 `MZGLShapeSource`. Configure the appearance of an `MZGLShapeSource`’s or
 `MZGLVectorTileSource`’s shape collection collectively using an
 `MZGLSymbolStyleLayer` object, or use multiple instances of
 `MZGLCircleStyleLayer`, `MZGLFillStyleLayer`, and `MZGLLineStyleLayer` to
 configure the appearance of each kind of shape inside the collection.

 You cannot add an `MZGLShapeCollection` object directly to a map view as an
 annotation. However, you can create individual `MZGLPointAnnotation`,
 `MZGLPolyline`, and `MZGLPolygon` objects from the `shapes` array and add those
 annotation objects to the map view using the `-[MZGLMapView addAnnotations:]`
 method.

 To represent a collection of point, polyline, or polygon shapes, it may be more
 convenient to use an `MZGLPointCollection`, `MGLMultiPolyline`, or
 `MGLMultiPolygon` object, respectively. To access a shape collection’s
 attributes, use the corresponding `MZGLFeature` object.

 A shape collection is known as a
 <a href="https://tools.ietf.org/html/rfc7946#section-3.1.8">GeometryCollection</a>
 geometry in GeoJSON.
 */
MGL_EXPORT
@interface MZGLShapeCollection : MZGLShape

/**
 An array of shapes forming the shape collection.
 */
@property (nonatomic, copy, readonly) NSArray<MZGLShape *> *shapes;

/**
 Creates and returns a shape collection consisting of the given shapes.

 @param shapes The array of shapes defining the shape collection. The data in
    this array is copied to the new object.
 @return A new shape collection object.
 */
+ (instancetype)shapeCollectionWithShapes:(NSArray<MZGLShape *> *)shapes;

@end

NS_ASSUME_NONNULL_END
