#import <Foundation/Foundation.h>

#import "MZGLFoundation.h"
#import "MZGLPolyline.h"
#import "MZGLPolygon.h"
#import "MZGLPointAnnotation.h"
#import "MZGLPointCollection.h"
#import "MZGLShapeCollection.h"
#import "MZGLCluster.h"

NS_ASSUME_NONNULL_BEGIN

/**
 The `MZGLFeature` protocol is used to provide details about geographic features
 contained in an `MZGLShapeSource` or `MZGLVectorTileSource` object. Each concrete
 subclass of `MZGLShape` in turn has a subclass that conforms to this protocol. A
 feature object associates a shape with an optional identifier and attributes.

 You can add custom data to display on the map by creating feature objects and
 adding them to an `MZGLShapeSource` using the
 `-[MZGLShapeSource initWithIdentifier:shape:options:]` method or
 `MZGLShapeSource.shape` property.

 In addition to adding data to the map, you can also extract data from the map:
 `-[MZGLMapView visibleFeaturesAtPoint:]` and related methods return feature
 objects that correspond to features in the source. This enables you to inspect
 the properties of features in vector tiles loaded by `MZGLVectorTileSource`
 objects. You also reuse these feature objects as overlay annotations.

 While it is possible to add `MZGLFeature`-conforming objects to the map as
 annotations using `-[MZGLMapView addAnnotations:]` and related methods, doing so
 has trade-offs:

 - Features added as annotations will not have `identifier` or `attributes`
 properties when used with feature querying.

 - Features added as annotations become interactive. Taps and selection can be
 handled in `-[MZGLMapViewDelegate mapView:didSelectAnnotation:]`.
 */
@protocol MZGLFeature <MZGLAnnotation>

/**
 An object that uniquely identifies the feature in its containing content
 source.

 You can configure an `MZGLVectorStyleLayer` object to include or exclude a
 specific feature in an `MZGLShapeSource` or `MZGLVectorTileSource`. In the
 `MZGLVectorStyleLayer.predicate` property, compare the special `$id` attribute
 to the feature’s identifier.

 In vector tiles loaded by `MZGLVectorTileSource` objects, the identifier
 corresponds to the
 <a href="https://github.com/mapbox/vector-tile-spec/tree/master/2.1#42-features">feature identifier</a>
 (`id`). If the source does not specify the feature’s identifier, the value of
 this property is `nil`. If specified, the identifier may be an integer,
 floating-point number, or string. These data types are mapped to instances of
 the following Foundation classes:

 <table>
 <thead>
 <tr><th>In the tile source</th><th>This property</th></tr>
 </thead>
 <tbody>
 <tr><td>Integer</td>               <td><code>NSNumber</code> (use the <code>unsignedLongLongValue</code> or <code>longLongValue</code> property)</td></tr>
 <tr><td>Floating-point number</td> <td><code>NSNumber</code> (use the <code>doubleValue</code> property)</td></tr>
 <tr><td>String</td>                <td><code>NSString</code></td></tr>
 </tbody>
 </table>

 For details about the identifiers used in most Mapbox-provided styles, consult
 the
 <a href="https://www.mapbox.com/vector-tiles/mapbox-streets/">Mapbox Streets</a>
 layer reference.

 The identifier should be set before adding the feature to an `MZGLShapeSource`
 object; setting it afterwards has no effect on the map’s contents. While it is
 possible to change this value on feature instances obtained from
 `-[MZGLMapView visibleFeaturesAtPoint:]` and related methods, doing so likewise
 has no effect on the map’s contents.
 */
@property (nonatomic, copy, nullable) id identifier;

/**
 A dictionary of attributes for this feature.

 You can configure an `MZGLVectorStyleLayer` object to include or exclude a
 specific feature in an `MZGLShapeSource` or `MZGLVectorTileSource`. In the
 `MZGLVectorStyleLayer.predicate` property, compare a key of the attribute
 dictionary to the value you want to include. For example, if you want an
 `MZGLLineStyleLayer` object to display only important features, you might assign
 a value above 50 to the important features’ `importance` attribute, then set
 `MZGLVectorStyleLayer.predicate` to an `NSPredicate` with the format
 `importance > 50`.

 You can also configure many layout and paint attributes of an `MZGLStyleLayer`
 object to match the value of an attribute in this dictionary whenever it
 renders this feature. For example, if you display features in an
 `MZGLShapeSource` using an `MZGLCircleStyleLayer`, you can assign a `halfway`
 attribute to each of the source’s features, then set
 `MZGLCircleStyleLayer.circleRadius` to an expression for the key path `halfway`.
 
 The `MZGLSymbolStyleLayer.text` and `MZGLSymbolStyleLayer.iconImageName`
 properties allow you to use attributes yet another way. For example, to label
 features in an `MZGLShapeSource` object by their names, you can assign a `name`
 attribute to each of the source’s features, then set
 `MZGLSymbolStyleLayer.text` to an expression for the constant string value
 `{name}`. See the
 <a href="../predicates-and-expressions.html">Predicates and Expressions</a>
 guide for more information about expressions.

 In vector tiles loaded by `MZGLVectorTileSource` objects, the keys and values of
 each feature’s attribute dictionary are determined by the source. Each
 attribute name is a string, while each attribute value may be a null value,
 Boolean value, integer, floating-point number, or string. These data types are
 mapped to instances of the following Foundation classes:

 <table>
 <thead>
 <tr><th>In the tile source</th><th>In this dictionary</th></tr>
 </thead>
 <tbody>
 <tr><td>Null</td>                  <td><code>NSNull</code></td></tr>
 <tr><td>Boolean</td>               <td><code>NSNumber</code> (use the <code>boolValue</code> property)</td></tr>
 <tr><td>Integer</td>               <td><code>NSNumber</code> (use the <code>unsignedLongLongValue</code> or <code>longLongValue</code> property)</td></tr>
 <tr><td>Floating-point number</td> <td><code>NSNumber</code> (use the <code>doubleValue</code> property)</td></tr>
 <tr><td>String</td>                <td><code>NSString</code></td></tr>
 </tbody>
 </table>

 For details about the attribute names and values found in Mapbox-provided
 vector tile sources, consult the
 <a href="https://www.mapbox.com/vector-tiles/mapbox-streets/">Mapbox Streets</a>
 and
 <a href="https://www.mapbox.com/vector-tiles/mapbox-terrain/">Mapbox Terrain</a>
 layer references.
 
 When adding a feature to an `MZGLShapeSource`, use the same Foundation types
 listed above for each attribute value. In addition to the Foundation types, you
 may also set an attribute to an `NSColor` (macOS) or `UIColor` (iOS), which
 will be converted into its
 <a href="https://maplibre.org/maplibre-gl-js-docs/style-spec/#types-color">CSS string representation</a>
 when the feature is added to an `MZGLShapeSource`. This can be convenient when
 using the attribute to supply a value for a color-typed layout or paint
 attribute via a key path expression.

 Note that while it is possible to change this value on feature
 instances obtained from `-[MZGLMapView visibleFeaturesAtPoint:]` and related
 methods, there will be no effect on the map. Setting this value can be useful
 when the feature instance is used to initialize an `MZGLShapeSource` and that
 source is added to the map and styled.
 */
@property (nonatomic, copy) NSDictionary<NSString *, id> *attributes;

/**
 Returns the feature attribute for the given attribute name.

 See the `attributes` property’s documentation for details on keys and values
 associated with this method.
 */
- (nullable id)attributeForKey:(NSString *)key;

/**
 Returns a dictionary that can be serialized as a GeoJSON Feature representation
 of an instance of an `MZGLFeature` subclass.

 The dictionary includes a `geometry` key corresponding to the receiver’s
 underlying geometry data, a `properties` key corresponding to the receiver’s
 `attributes` property, and an `id` key corresponding to the receiver’s
 `identifier` property.
 */
- (NSDictionary<NSString *, id> *)geoJSONDictionary;

@end

/**
 An `MGLEmptyFeature` object associates an empty shape with an optional
 identifier and attributes.
 */
MGL_EXPORT
@interface MGLEmptyFeature : MZGLShape <MZGLFeature>
@end

/**
 An `MGLPointFeature` object associates a point shape with an optional
 identifier and attributes.
 
 #### Related examples
 See the <a href="https://docs.mapbox.com/ios/maps/examples/runtime-multiple-annotations/">
 Dynamically style interactive points</a> example to learn how to initialize
 `MGLPointFeature` objects and add them to your map.
 */
MGL_EXPORT
@interface MGLPointFeature : MZGLPointAnnotation <MZGLFeature>
@end

/**
 An `MGLPointFeatureCluster` object associates a point shape (with an optional
 identifier and attributes) and represents a point cluster.
 
 @see `MZGLCluster`
 
 #### Related examples
 See the <a href="https://docs.mapbox.com/ios/maps/examples/clustering/">
 Clustering point data</a> example to learn how to initialize
 clusters and add them to your map.
 */
MGL_EXPORT
@interface MGLPointFeatureCluster : MGLPointFeature <MZGLCluster>
@end

/**
 An `MZGLPolylineFeature` object associates a polyline shape with an optional
 identifier and attributes.

 A polyline feature is known as a
 <a href="https://tools.ietf.org/html/rfc7946#section-3.1.4">LineString</a>
 feature in GeoJSON.
 
 #### Related examples
 See the <a href="https://docs.mapbox.com/ios/maps/examples/line-geojson/">
 Add a line annotation from GeoJSON</a> example to learn how to initialize an
 `MZGLPolylineFeature` and add it to an `MZGLMapView` object.
 */
MGL_EXPORT
@interface MZGLPolylineFeature : MZGLPolyline <MZGLFeature>
@end

/**
 An `MZGLPolygonFeature` object associates a polygon shape with an optional
 identifier and attributes.
 */
MGL_EXPORT
@interface MZGLPolygonFeature : MZGLPolygon <MZGLFeature>
@end

/**
 An `MZGLPointCollectionFeature` object associates a point collection with an
 optional identifier and attributes.

 A point collection feature is known as a
 <a href="https://tools.ietf.org/html/rfc7946#section-3.1.3">MultiPoint</a>
 feature in GeoJSON.
 */
MGL_EXPORT
@interface MZGLPointCollectionFeature : MZGLPointCollection <MZGLFeature>
@end

// https://github.com/mapbox/mapbox-gl-native/issues/7473
@compatibility_alias MZGLMultiPointFeature MZGLPointCollectionFeature;

/**
 An `MGLMultiPolylineFeature` object associates a multipolyline shape with an
 optional identifier and attributes.

 A multipolyline feature is known as a
 <a href="https://tools.ietf.org/html/rfc7946#section-3.1.5">MultiLineString</a>
 feature in GeoJSON.
 */
MGL_EXPORT
@interface MGLMultiPolylineFeature : MGLMultiPolyline <MZGLFeature>
@end

/**
 An `MGLMultiPolygonFeature` object associates a multipolygon shape with an
 optional identifier and attributes.
 */
MGL_EXPORT
@interface MGLMultiPolygonFeature : MGLMultiPolygon <MZGLFeature>
@end

/**
 An `MZGLShapeCollectionFeature` object associates a shape collection with an
 optional identifier and attributes.
 
 `MZGLShapeCollectionFeature` is most commonly used to add multiple shapes to a
 single `MZGLShapeSource`. Configure the appearance of an `MZGLSource`’s shape
 collection collectively using an `MZGLSymbolStyleLayer` object, or use multiple
 instances of `MZGLCircleStyleLayer`, `MZGLFillStyleLayer`, and
 `MZGLLineStyleLayer` to configure the appearance of each kind of shape inside
 the collection.

 A shape collection feature is known as a
 <a href="https://tools.ietf.org/html/rfc7946#section-3.3">feature collection</a>
 in GeoJSON.
 
 #### Related examples
 See the <a href="https://docs.mapbox.com/ios/maps/examples/shape-collection/">
 Add multiple shapes from a single shape source</a> example to learn how to
 add shape data to your map using an `MZGLShapeCollectionFeature` object.
 */
MGL_EXPORT
@interface MZGLShapeCollectionFeature : MZGLShapeCollection <MZGLFeature>

@property (nonatomic, copy, readonly) NSArray<MZGLShape<MZGLFeature> *> *shapes;

+ (instancetype)shapeCollectionWithShapes:(NSArray<MZGLShape<MZGLFeature> *> *)shapes;

@end

NS_ASSUME_NONNULL_END
