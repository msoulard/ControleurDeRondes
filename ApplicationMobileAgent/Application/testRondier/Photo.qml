import QtMultimedia 5.15
import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtQml.Models 2.15

Page {
    visible: true

    title: qsTr("Caméra")

    property alias toolButton: toolButton
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
            bottom: parent.bottom
            bottomMargin: 20
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
        }
        background: Rectangle { color:  "green" }
    }
}

