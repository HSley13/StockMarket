import QtQuick;
import QtQuick.Controls;

BackGround{
  id: backGround;

  Rectangle {
    id: homeWindow;
    color:"black";
    radius: 40;
    anchors.top: backGround.searchField.bottom;
    anchors.bottom: parent.bottom;
    anchors.right: parent.right;
    anchors.topMargin: 10;
    anchors.bottomMargin: 10;
    anchors.rightMargin: 10;
    anchors.left: backGround.menuPanel.right;

    PolarGraph{
      id: polarGraph;
      anchors.top: homeWindow.top;
      anchors.left: homeWindow.left;
      anchors.margins: 20;
      color: "white";
    }   

    // CandleStick{
    //   id: candleStick;
    //   anchors.top: homeWindow.top;
    //   anchors.right: homeWindow.right;
    //   anchors.margins: 20;
    //   color: "white";
    // }

    Profile{
      id: profile;
      anchors.top: homeWindow.top;
      anchors.right: homeWindow.right;
      anchors.margins: 20;
    }
  }
}
