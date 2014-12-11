import QtQuick 2.0
import QtQuick.Controls 1.2
import Tools 1.0

Rectangle {
    width: 100
    height: 62
    color: "#607d8b"
    Label {
        anchors.centerIn: parent
        text: qsTr("24 years")
        font.pixelSize: units.dp(20)
        color: "white"
    }
}

