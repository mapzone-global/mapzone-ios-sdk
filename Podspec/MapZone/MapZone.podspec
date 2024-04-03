Pod::Spec.new do |s|  
    s.name              = 'MapZone'
    s.version           = '1.0.3'
    s.summary           = 'MapZone Maps'
    s.homepage          = 'https://github.com/mapzone-global'

    s.author            = { 'ThanhDT' => 'thanhdt@vietmap.vn' }
    s.license = { :type => "MIT", :text => "MIT License" }

    s.platform          = :ios
    # change the source location
    s.source            = { :git => 'https://github.com/mapzone-global/mapzone-ios-sdk.git', :tag  => s.version }
    s.ios.deployment_target = '12.0'
    s.ios.vendored_frameworks = 'MapZone.xcframework'
end 