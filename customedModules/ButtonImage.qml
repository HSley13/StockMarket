import QtQuick;
import QtQuick.Controls;

Rectangle{
  id: root;

  required property string imageSource;
  signal itemClicked();
  property alias color: root.color;

  radius: width / 2;
  color: mouseArea.pressed ? "gray" : "white";

  Image{
    id: img;
    source: root.imageSource;
    mipmap: true;

    fillMode: Image.PreserveAspectFit;
    asynchronous: true;

    width: parent.width; 
    height: width; 
  }

  MouseArea{
    id: mouseArea;
    anchors.fill: parent;

    onClicked: root.itemClicked();
  }
}

