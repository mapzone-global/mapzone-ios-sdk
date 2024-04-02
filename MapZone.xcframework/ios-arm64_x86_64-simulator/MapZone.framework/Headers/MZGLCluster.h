#import "MZGLFoundation.h"

@protocol MZGLFeature;

NS_ASSUME_NONNULL_BEGIN

/**
 An `NSUInteger` constant used to indicate an invalid cluster identifier.
 This indicates a missing cluster feature.
 */
FOUNDATION_EXTERN MGL_EXPORT const NSUInteger MZGLClusterIdentifierInvalid;

/**
 A protocol that feature subclasses (i.e. those already conforming to
 the `MZGLFeature` protocol) conform to if they represent clusters.
 
 Currently the only class that conforms to `MZGLCluster` is
 `MGLPointFeatureCluster` (a subclass of `MGLPointFeature`).
 
 To check if a feature is a cluster, check conformity to `MZGLCluster`, for
 example:
 
 ```swift
 let shape = try! MZGLShape(data: clusterShapeData, encoding: String.Encoding.utf8.rawValue)
 
 guard let pointFeature = shape as? MGLPointFeature else {
     throw ExampleError.unexpectedFeatureType
 }
 
 // Check for cluster conformance
 guard let cluster = pointFeature as? MZGLCluster else {
     throw ExampleError.featureIsNotACluster
 }
 
 // Currently the only supported class that conforms to `MZGLCluster` is
 // `MGLPointFeatureCluster`
 guard cluster is MGLPointFeatureCluster else {
     throw ExampleError.unexpectedFeatureType
 }
 ```
 */
MGL_EXPORT
@protocol MZGLCluster <MZGLFeature>

/** The identifier for the cluster. */
@property (nonatomic, readonly) NSUInteger clusterIdentifier;

/** The number of points within this cluster */
@property (nonatomic, readonly) NSUInteger clusterPointCount;

@end

NS_ASSUME_NONNULL_END
