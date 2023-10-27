// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "VietMap",
    products: [
        .library(
            name: "VietMap",
            targets: ["Mapbox"])
    ],
    dependencies: [
    ],    
    targets: [
        .binaryTarget(
            name: "Mapbox",
            url: "https://github.com/vietmap-company/maps-sdk-ios/raw/main/VietMap.xcframework.zip",
            checksum: "356f31d9626d9a6e4f6282b4a90ae46bd9373f9011467a67114d7cb41460f8bd") 
            ]
)