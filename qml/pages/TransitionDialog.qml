import QtQuick 2.0
import Sailfish.Silica 1.0
import org.inno.commands 1.0

Dialog {
    property bool name

    Commands{
        id : commands
    }

    Column {
        anchors.fill: parent

        DialogHeader { }
        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            text: "After accepting, you won't be able to go back without rebooting"
            wrapMode: Text.WordWrap
        }

    }

    onDone: if (result == DialogResult.Accepted) {
                commands.switchWorld("","","");
                console.log("In safe mode")
            }
}
