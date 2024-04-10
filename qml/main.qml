import QtQuick 2.15

Window {
    width: 640
    height: 480
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height
    visibility: Window.Minimized
    title: qsTr("Password Manager")
    color: theme.color("background")

    Row {
        anchors.centerIn: parent
        spacing: 15
        Icon { size: 48 }
        AppText {
            text: "TEXT"
            font.pixelSize: 48
            // anchors.verticalCenter: parent.verticalCenter
        }
        AppText {
            text: "text 2"
            font.pixelSize: 36
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
