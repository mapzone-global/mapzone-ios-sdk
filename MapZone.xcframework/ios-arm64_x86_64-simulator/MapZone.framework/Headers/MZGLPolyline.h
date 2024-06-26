#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "MZGLFoundation.h"
#import "MZGLMultiPoint.h"
#import "MZGLOverlay.h"

#import "MZGLTypes.h"

NS_ASSUME_NONNULL_BEGIN

/**
 An `MZGLPolyline` object represents a shape consisting of two or more vertices,
 specified as `CLLocationCoordinate2D` instances, and the line segments that
 connect them. For example, you could use an polyline to represent a road or the
 path along which something moves.

 You can add polyline shapes to the map by adding them to an `MZGLShapeSource`
 object. Configure the appearance of an `MZGLShapeSource`’s or
 `MZGLVectorTileSource`’s polylines collectively using an `MZGLLineStyleLayer` or
 `MZGLSymbolStyleLayer` object. To access a polyline’s attributes, use an
 `MZGLPolylineFeature` object.

 Alternatively, you can add a polyline overlay directly to a map view using the
 `-[MZGLMapView addAnnotation:]` or `-[MZGLMapView addOverlay:]` method. Configure
 a polyline overlay’s appearance using
 `-[MZGLMapViewDelegate mapView:strokeColorForShapeAnnotation:]` and
 `-[MZGLMapViewDelegate mapView:lineWidthForPolylineAnnotation:]`.

 The vertices are automatically connected in the order in which you provide
 them. The first and last vertices are not connected to each other, but you can
 specify the same `CLLocationCoordinate2D` as the first and last vertices in
 order to close the polyline. To fill the space within the shape, use an
 `MZGLPolygon` object. To group multiple polylines together in one shape, use an
 `MGLMultiPolyline` or `MZGLShapeCollection` object.

 To make the polyline go across the antimeridian or international date line, 
 specify some longitudes less than −180 degrees or greater than 180 degrees.
 For example, a polyline that stretches from Tokyo to San Francisco would have
 coordinates of (35.68476, -220.24257) and (37.78428, -122.41310).
 
 ```swift
 let coordinates = [
     CLLocationCoordinate2D(latitude: 35.68476, longitude: -220.24257),
     CLLocationCoordinate2D(latitude: 37.78428, longitude: -122.41310)
 ]
 let polyline = MZGLPolyline(coordinates: coordinates, count: UInt(coordinates.count))
 ```

 A polyline is known as a
 <a href="https://tools.ietf.org/html/rfc7946#section-3.1.4">LineString</a>
 geometry in GeoJSON.
 
 #### Related examples
 See the <a href="https://docs.mapbox.com/ios/maps/examples/annotation-models/">
 Annotation models</a> example to learn how to add an `MGLPolyine` object to
 your map.
 */
MGL_EXPORT
@interface MZGLPolyline : MZGLMultiPoint <MZGLOverlay>

/**
 Creates and returns an `MZGLPolyline` object from the specified set of
 coordinates.

 @param coords The array of coordinates defining the shape. The data in this
    array is copied to the new object.
 @param count The number of items in the `coords` array.
 @return A new polyline object.
 */
+ (instancetype)polylineWithCoordinates:(const CLLocationCoordinate2D *)coords count:(NSUInteger)count;

@end

/**
 An `MGLMultiPolyline` object represents a shape consisting of one or more
 polylines. For example, you could use a multipolyline shape to represent both
 sides of a divided highway (dual carriageway), excluding the median (central
 reservation): each carriageway would be a distinct `MZGLPolyline` object.

 You can add multipolyline shapes to the map by adding them to an
 `MZGLShapeSource` object. Configure the appearance of an `MZGLShapeSource`’s or
 `MZGLVectorTileSource`’s multipolylines collectively using an
 `MZGLLineStyleLayer` or `MZGLSymbolStyleLayer` object.

 You cannot add an `MGLMultiPolyline` object directly to a map view using
 `-[MZGLMapView addAnnotation:]` or `-[MZGLMapView addOverlay:]`. However, you can
 add the `polylines` array’s items as overlays individually.

 A multipolyline is known as a
 <a href="https://tools.ietf.org/html/rfc7946#section-3.1.5">MultiLineString</a>
 geometry in GeoJSON.
 */
MGL_EXPORT
@interface MGLMultiPolyline : MZGLShape <MZGLOverlay>

/**
 An array of polygons forming the multipolyline.
 */
@property (nonatomic, copy, readonly) NSArray<MZGLPolyline *> *polylines;

/**
 Creates and returns a multipolyline object consisting of the given polylines.

 @param polylines The array of polylines defining the shape.
 @return A new multipolyline object.
 */
+ (instancetype)multiPolylineWithPolylines:(NSArray<MZGLPolyline *> *)polylines;

@end

NS_ASSUME_NONNULL_END
