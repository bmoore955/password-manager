import QtQuick 2.15
import "qrc:/fonts/MaterialDesignIconGlyphs.js" as MaterialGlyphs

AppText {
    id: iconBase

    property int size: 24
    property string icon: "settings"
    readonly property string iconCode: {
        if (MaterialGlyphs.glyphs[iconBase.icon] === undefined)
            return "";
        return MaterialGlyphs.glyphs[iconBase.icon];
    }

    width: size
    height: size
    text: iconCode
    horizontalAlignment: Text.AlignHCenter
    font {
        family: materialFont.name
        pixelSize: size
    }

    FontLoader {
        id: materialFont
        source: "qrc:/fonts/materialdesignicons-webfont.ttf"
    }
}
