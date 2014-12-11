import QtQuick 2.2
import QtQuick.Window 2.0
import Tools 1.0

Window {
    visible: true

    Component.onCompleted:
    {
        units.pixelRatio = Screen.pixelDensity / (160 * 2.54 / 100) * Screen.devicePixelRatio
        console.log("<4b49c54b> Pixel ration: " +  units.pixelRatio + " density: " + Screen.pixelDensity)

        if (Qt.platform.os === "linux")
        {
            width = 320
            height = 480
        }
        timer.start()
    }

    Timer {
        id: timer
        onTriggered: loader.active = true
    }

    Banner {
        id: banner
        anchors.fill: parent
    }

    Loader {
        id: loader
        anchors.fill: parent
        source: "MainWindow.qml"
        active: false
        visible: false
        onLoaded: {
            banner.visible = false
            visible = true
        }
    }
}

//Window {
//    title: qsTr("23 years")
////    width: 300
////    height: 400

//    property var model: [
//        { title: "Good day", date: "12.02.2014", color: "yellow" },
//        { title: "Bad day", date: "23.05.2013", color: "red" },
//        { title: "Birth day", date: "01.01", color: "green" },
//        { title: "Skynet", date: "2025", color: "blue" }
//    ]
//    visible: true

//    id: root

//    Image {
//        x: -1000 + -listView.contentX * 0.2
//        width: 10000000
//        height: parent.height
//        source: "background.png"
//        fillMode: Image.Tile
//    }

//    ListView {
//        id: listView
//        model: root.model

//        delegate: Card {
//            property var item: model.modelData ? model.modelData : model

//            date: item.date
//            description: item.title
//            color: item.color
//            width: root.width
//            height: root.height
//        }

//        anchors.fill: parent
//        orientation: ListView.Horizontal
//        snapMode: ListView.SnapOneItem
//    }
//}
