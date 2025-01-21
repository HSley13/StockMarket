import QtQuick;
import QtQuick.Controls;
import QtQuick.Controls.Basic;

Rectangle{
  id: root;

  property alias inputField: textInput.text;
  property string imageSource;
  property string placeHolder;
  property alias echoMode: textInput.echoMode;
  property bool isSearching: false;
  property color borderColor:  textInput.focus ? "gray" : "black";

  signal accepted(string value);  

  radius: 20;
  border.color: root.borderColor;
  border.width: textInput.focus ? 4 : 2;
  opacity: enabled ? 1 : 0.6;

  TextField{
    id: textInput;

    anchors.fill: parent;
    anchors.margins: 2;

    clip: true;
    wrapMode: Text.Wrap;
    font.pixelSize: 14;
    color: "black";

    placeholderText: root.placeHolder;
    placeholderTextColor: "black";

    leftPadding: toggleImage.width + 10;
    verticalAlignment: TextField.AlignVCenter;

    onTextChanged: {
      if(isSearching) {

      }
    }

    onAccepted:{
      root.accepted(text);
    }

    background: Rectangle{
      radius: root.radius - 2;
      implicitWidth: 200;
      implicitHeight: 40;
      color: "transparent";
    }

    Image{
      id: toggleImage;
      anchors.left: parent.left;
      anchors.leftMargin: 5;
      anchors.verticalCenter: parent.verticalCenter;
      width: 20;
      height: 20;
      mipmap: true;
      source: root.imageSource;
    }
  }

  Component.onCompleted: textInput.focus = false;
}
