#import "MZGLFoundation.h"

/**
 :nodoc:
 Bitmask values that describe why a camera move occurred.

 Values of this type are passed to the `MZGLMapView`'s delegate in the following methods:

 - `-mapView:shouldChangeFromCamera:toCamera:reason:`
 - `-mapView:regionWillChangeWithReason:animated:`
 - `-mapView:regionIsChangingWithReason:`
 - `-mapView:regionDidChangeWithReason:animated:`

 It's important to note that it's almost impossible to perform a rotate without zooming (in or out),
 so if you'll often find `MZGLCameraChangeReasonGesturePinch` set alongside `MZGLCameraChangeReasonGestureRotate`.

 Since there are several reasons why a zoom or rotation has occurred, it is worth considering
 creating a combined constant, for example:

 ```
 static const MZGLCameraChangeReason anyZoom = MZGLCameraChangeReasonGesturePinch |
                                                MZGLCameraChangeReasonGestureZoomIn |
                                                MZGLCameraChangeReasonGestureZoomOut |
                                                MZGLCameraChangeReasonGestureOneFingerZoom;

 static const MZGLCameraChangeReason anyRotation = MZGLCameraChangeReasonResetNorth | MZGLCameraChangeReasonGestureRotate;
 ```
 */
typedef NS_OPTIONS(NSUInteger, MZGLCameraChangeReason)
{
    /// :nodoc: The reason for the camera change has not be specified.
    MZGLCameraChangeReasonNone = 0,

    /// :nodoc: Set when a public API that moves the camera is called. This may be set for some gestures,
    /// for example MZGLCameraChangeReasonResetNorth.
    MZGLCameraChangeReasonProgrammatic = 1 << 0,

    /// :nodoc: The user tapped the compass to reset the map orientation so North is up.
    MZGLCameraChangeReasonResetNorth = 1 << 1,

    /// :nodoc: The user panned the map.
    MZGLCameraChangeReasonGesturePan = 1 << 2,

    /// :nodoc: The user pinched to zoom in/out.
    MZGLCameraChangeReasonGesturePinch = 1 << 3,

    // :nodoc: The user rotated the map.
    MZGLCameraChangeReasonGestureRotate = 1 << 4,

    /// :nodoc: The user zoomed the map in (one finger double tap).
    MZGLCameraChangeReasonGestureZoomIn = 1 << 5,

    /// :nodoc: The user zoomed the map out (two finger single tap).
    MZGLCameraChangeReasonGestureZoomOut = 1 << 6,

    /// :nodoc: The user long pressed on the map for a quick zoom (single tap, then long press and drag up/down).
    MZGLCameraChangeReasonGestureOneFingerZoom = 1 << 7,

    // :nodoc: The user panned with two fingers to tilt the map (two finger drag).
    MZGLCameraChangeReasonGestureTilt = 1 << 8,

    // :nodoc: Cancelled
    MZGLCameraChangeReasonTransitionCancelled = 1 << 16

};
