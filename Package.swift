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
            checksum: "76d93f7f4376cae8b4139726d80854901e17f1f4f51bfcd51df3b661d8d986a3") 
            ]
)