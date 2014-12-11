import QtQuick 2.0
import QtQuick.Layouts 1.1

Item {
    property string description
    property string date
    property color color
    width: 100
    height: 200

    id: root

    function colorLighting(color) {
        return (color.r + color.g + color.b) / 3;
    }

    Rectangle {
        id: card
        color: root.color
        anchors.fill: parent
        anchors.margins: 40
        clip: true

        scale: mouseArea.pressed && mouseArea.containsMouse ? 0.98 : 1
        Behavior on scale {
            NumberAnimation { duration: 200; easing.type: Easing.OutQuad }
        }

        property color textColor: "black"

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20

            Text {
                text: root.description
                Layout.fillWidth: true
                font.pixelSize: 16
                color: card.textColor
            }

            Text {
                text: root.date
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                Layout.fillHeight: true
                Layout.fillWidth: true
                font.pixelSize: 35
                font.bold: true
                color: card.textColor
            }
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent

        }

        states: State {
            when: root.colorLighting(root.color) < 0.5
            PropertyChanges {
                target: card
                textColor: "white"
            }
        }
    }
}
