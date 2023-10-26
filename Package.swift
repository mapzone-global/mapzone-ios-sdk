// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "VietMap",
    products: [
        .library(
            name: "VietMap",
            targets: ["VietMap"])
    ],
    dependencies: [
    ],    
    targets: [
        .binaryTarget(
            name: "Mapbox",
            url: "https://github.com/vietmap-company/maps-sdk-ios/raw/main/VietMap.xcframework.zip",
            checksum: "b3ec725c6dd6f7e61536b08f34009b372e133a74329230f885029ea21b5575b7") 
            ]
)