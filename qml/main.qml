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
        Icon {}
        Text {
            text: "text"
            color: "white"
            anchors.verticalCenter: parent.verticalCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
}
