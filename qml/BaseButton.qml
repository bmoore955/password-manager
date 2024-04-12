import QtQuick 2.15

Rectangle {
    id: baseButton

    property bool isPressed: false
    property string backgroundColor: theme.color("background")
    property string textColor: theme.color("text")

    signal clicked()

    width: 100
    height: 50
    radius: 10
    color: isPressed ? Qt.darker(baseButton.backgroundColor, 1.5) : baseButton.backgroundColor
    border {
        color: theme.color("text")
        width: isPressed ? 2 : 0
    }

    MouseArea {
        anchors.fill: parent
        onPressed: baseButton.isPressed = true;
        onReleased: baseButton.isPressed = false;
        onClicked: baseButton.clicked();
    }
}
