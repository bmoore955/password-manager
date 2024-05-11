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
        spacing: 10

        BaseButton {
            backgroundColor: theme.color("base-40")
            onClicked: tester.addRandom();

            AppText {
                anchors.centerIn: parent
                text: "Add"
            }
        }
    }
}
