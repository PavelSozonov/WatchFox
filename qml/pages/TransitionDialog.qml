import QtQuick 2.0
import Sailfish.Silica 1.0

Dialog {
    property bool name

    Column {
        anchors.fill: parent

        DialogHeader { }
        Label {
            anchors.centerIn: parent
            width: applicationWindow.width
            text: "After accepting, you won't be able to go back without rebooting"
            wrapMode: Text.WrapAnywhere
        }
    }
}
