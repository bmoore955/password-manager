import QtQuick 2.15
import "qrc:/fonts/MaterialDesignIconGlyphs.js" as MaterialGlyphs

Text {
    id: iconBase

    property string icon: "settings"
    property int size: 48

    width: size
    height: size
    font.pixelSize: size
    text: MaterialGlyphs.glyphs[iconBase.icon]
    color: theme.color("text")
    font.family: materialFont.name

    FontLoader {
        id: materialFont
        source: "qrc:/fonts/materialdesignicons-webfont.ttf"
    }
}
