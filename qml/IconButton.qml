import QtQuick 2.15

BaseButton {
    id: iconButton

    property int size: 50
    property alias iconCode: icon.icon

    width: iconButton.size
    height: iconButton.size
    backgroundColor: theme.color("base-40")

    Icon {
        id: icon
        anchors.centerIn: parent
        size: iconButton.size * 0.75
    }
}
