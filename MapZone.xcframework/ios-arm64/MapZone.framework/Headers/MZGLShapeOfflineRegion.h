#import <Foundation/Foundation.h>

#import "MZGLFoundation.h"
#import "MZGLOfflineRegion.h"
#import "MZGLShape.h"

NS_ASSUME_NONNULL_BEGIN

/**
 An offline region defined by a style URL, geographic shape, and
 range of zoom levels.
 
 ### Example
 ```swift
 var coordinates = [
     CLLocationCoordinate2D(latitude: 45.522585, longitude: -122.685699),
     CLLocationCoordinate2D(latitude: 45.534611, longitude: -122.708873),
     CLLocationCoordinate2D(latitude: 45.530883, longitude: -122.678833)
 ]
 
 let triangle = MZGLPolygon(coordinates: &coordinates, count: UInt(coordinates.count))
 let region = MZGLShapeOfflineRegion(styleURL: MZGLStyle.lightStyleURL, shape: triangle, fromZoomLevel: 11, toZoomLevel: 14)
 let context = "Triangle Region".data(using: .utf8)
 MZGLOfflineStorage.shared.addPack(for: region, withContext: context!)
 ```
 
 This class requires fewer resources than MZGLTilePyramidOfflineRegion
 for irregularly shaped regions.
 */
MGL_EXPORT
@interface MZGLShapeOfflineRegion : NSObject <MZGLOfflineRegion, NSSecureCoding, NSCopying>

/**
 The shape for the geographic region covered by the downloaded
 tiles.
 */
@property (nonatomic, readonly) MZGLShape *shape;

/**
 The minimum zoom level for which to download tiles and other resources.

 For more information about zoom levels, `-[MZGLMapView zoomLevel]`.
 */
@property (nonatomic, readonly) double minimumZoomLevel;

/**
 The maximum zoom level for which to download tiles and other resources.

 For more information about zoom levels, `-[MZGLMapView zoomLevel]`.
 */
@property (nonatomic, readonly) double maximumZoomLevel;

- (instancetype)init NS_UNAVAILABLE;

/**
 Initializes a newly created offline region with the given style URL, geometry,
 and range of zoom levels.

 This is the designated initializer for `MZGLShapeOfflineRegion`.

 @param styleURL URL of the map style for which to download resources. The URL
    may be a full HTTP or HTTPS URL or a canonical URL.
    Specify `nil` for the default style.
    Relative file URLs cannot be used as offline style URLs. To download the
    online resources required by a local style, specify a URL to an online copy
    of the style.
 @param shape The shape of the geographic region to be covered by
    the downloaded tiles.
 @param minimumZoomLevel The minimum zoom level to be covered by the downloaded
    tiles. This parameter should be set to at least 0 but no greater than the
    value of the `maximumZoomLevel` parameter. For each required tile source, if
    this parameter is set to a value less than the tile source’s minimum zoom
    level, the download covers zoom levels down to the tile source’s minimum
    zoom level.
 @param maximumZoomLevel The maximum zoom level to be covered by the downloaded
    tiles. This parameter should be set to at least the value of the
    `minimumZoomLevel` parameter. For each required tile source, if this
    parameter is set to a value greater than the tile source’s minimum zoom
    level, the download covers zoom levels up to the tile source’s maximum zoom
    level.
 */
- (instancetype)initWithStyleURL:(nullable NSURL *)styleURL shape:(MZGLShape *)shape fromZoomLevel:(double)minimumZoomLevel toZoomLevel:(double)maximumZoomLevel NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
