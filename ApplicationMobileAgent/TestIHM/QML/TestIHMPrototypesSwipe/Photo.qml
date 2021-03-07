import QtMultimedia 5.15
import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtQml.Models 2.15

Page {
    //@disable-check M16
    visible: true
    //@disable-check M16
    width: 640
    //@disable-check M16
    height: 360
    //@disable-check M16
    title: qsTr("Caméra")

    //id: photo
    property alias toolButton: toolButton
    //property alias visu: visu
    //property alias page: page
    property alias video: video
    Camera {
        id: appareil
        exposure{
            exposureMode: Camera.ExposureAction
            manualIso: 800
        }
        focus{
            focusMode: CameraFocus.FocusContinuous
            focusPointMode: Camera.FocusPointAuto
        }
        imageProcessing{
            saturation: -1
            contrast: 1
        }
        flash.mode: Camera.FlashAuto
        //imageCapture.onImageCaptured: visu.source = preview
        captureMode: Camera.CaptureStillImage

        imageCapture {
            onImageCaptured: {
                console.log("image captured with preview="+preview);
                _Image_PhotoPreview.source = preview
            }
            onCaptureFailed: {
                console.log("capture failed with error " + message);
            }
            onImageMetadataAvailable: {
                console.log("image metadata available with key = " + key + " & value = " + value);
            }
            onImageSaved: {
                console.log("image saved with path " + path);
                console.log("image saved with resolved path (incorrect, returns asset://) " + Qt.resolvedUrl(path));
                console.log("image saved with forged path " + "file://" + path);
                _Image_PhotoPreview.source = "file://" + path

            }
        }
    }
    VideoOutput{
        id: video
        source: appareil
        anchors.fill: parent
        orientation: appareil.orientation
    }
    Image{
        id: visu
        fillMode: Image.PreserveAspectCrop
        anchors.fill: parent
    }
    ToolButton{
        id: toolButton
        anchors{
            top: parent.top
            topMargin: 20
            horizontalCenter: parent.horizontalCenter
        }
        icon{
            color: "black"
            width: 100
            height: 100
        }
        onClicked: {
            visu.visible = true;
            appareil.imageCapture.captureToLocalisation = "Anomalie"+Qt.formatDateTime(new Date(), "yyyyMMdd.hh:mm:ss")+".jpg";
            appareil.start();
            appareil.imageCapture.capture();
            //appareil.imageCapture.imageSaved(0, "/sdcard");
            //appareil.imageCapture.captureToLocation("/sdcard");
        }
        background: Rectangle { color:  "green" }
    }
    Rectangle {
        width: parent.width
        height: parent.height/2
        anchors.bottom: parent.bottom
        color: "#FF0000"

        clip: true
        Flickable {
            id: _Flickable
            anchors.fill: parent
            contentWidth: _Image_PhotoPreview.sourceSize.width
            contentHeight: _Image_PhotoPreview.sourceSize.height
            Image {
                id: _Image_PhotoPreview
                scale: 0.5
                fillMode: Image.PreserveAspectFit
                PinchArea {
                    anchors.fill: parent
                    pinch.target: _Image_PhotoPreview
                    enabled: true
                    pinch.minimumScale: 0.35
                    pinch.maximumScale: 2.0

                }
            }
        }
    }
}

