// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "MapZone",
    products: [
        .library(
            name: "MapZone",
            targets: ["Mapbox"])
    ],
    dependencies: [
    ],    
    targets: [
        .binaryTarget(
            name: "Mapbox",
            url: "https://github.com/mapzone-global/mapzone-ios-sdk/raw/main/MapZone.xcframework.zip",
            checksum: "e840b41117856c17d62c1fee271d3bfc4db8a702f41914ec7d97874795ed2011") 
            ]
)