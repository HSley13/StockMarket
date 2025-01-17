import QtQuick
import QtQuick.Controls

Rectangle {
  color: "#242323";
  anchors.fill: parent;
  property alias searchField: searchField;

  InputField{
    id: searchField;

    anchors.top: parent.top;
    anchors.horizontalCenter: parent.horizontalCenter;
    imageSource: "qrc:/QML/stockMarket/icons/search_icon.png";
    placeHolder: "Search Companies, NFTs, Collections";
    width: parent.width * 0.3;
    height: 35;
    anchors.margins: 10;
  }

  ButtonImage{
    id: profileButton;

    anchors.top: parent.top;
    anchors.right: parent.right;
    imageSource: "qrc:/QML/stockMarket/icons/profile_icon.png";
    width: 35;
    height: 35;
    anchors.margins: 10;
  }

  RoundedButton{
    id: upgradeButton;

    anchors.top: parent.top;
    anchors.right: profileButton.left;
    width: 90;
    height: 35;
    anchors.margins: 10;
    text: "Upgrade";
  }

}
