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
            url: "https://github.com/vietmap-company/maps-sdk-ios/raw/main/Mapbox.xcframework.zip",
            checksum: "7c4f43ce0c545bf2ce2dd642551e8c1689cfe0679f65454586c7387254603cd2") 
            ]
)