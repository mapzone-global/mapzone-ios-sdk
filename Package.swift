// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "Mapbox",
    products: [
        .library(
            name: "Mapbox",
            targets: ["Mapbox"])
    ],
    dependencies: [
    ],    
    targets: [
        .binaryTarget(
            name: "Mapbox",
            url: "https://github.com/vietmap-company/maps-sdk-ios/raw/main/Mapbox_1.0.4.xcframework.zip",
            checksum: "fdc960940561b783f5600d809de93d6d0f27fa29eceea6e9ea3e5f29c0a4b07e") 
            ]
)