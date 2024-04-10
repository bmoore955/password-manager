import QtQuick 2.15

Text {
    id: appText
    color: theme.color("text")
    verticalAlignment: Text.AlignVCenter
    anchors.verticalCenter: parent.verticalCenter
    font {
        family: "Nunito"
        pixelSize: 24
    }
}
