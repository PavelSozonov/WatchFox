import QtQuick 2.2
import Sailfish.Silica 1.0

Page {
    Column {
        anchors.fill: parent

        PageHeader { title: qsTr("Text Input Page")}
        TextField {
            placeholderText: qsTr("password")
            width: parent.width
            EnterKey.enabled: text.length > 0
//            EnterKey.iconSource: "image://theme/icon-m-enter-next"
            EnterKey.onClicked: textArea.focus = true
        }
    }
}
