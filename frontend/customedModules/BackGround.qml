import QtQuick
import QtQuick.Controls

Rectangle {
  color: "#242323";
  anchors.fill: parent;
  property alias searchField: searchField;
  property alias menuPanel: menuPanel;

  InputField{
    id: searchField;

    anchors.top: parent.top;
    anchors.horizontalCenter: parent.horizontalCenter;
    imageSource: "qrc:/QML/stockMarket/frontend/icons/search_icon.png";
    placeHolder: "Search Companies, NFTs, Collections";
    width: parent.width * 0.3;
    height: 35;
    anchors.margins: 10;
  }

  ButtonImage{
    id: profileButton;

    anchors.top: parent.top;
    anchors.right: parent.right;
    imageSource: "qrc:/QML/stockMarket/frontend/icons/profile_icon.png";
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

  MenuPanel{
    id: menuPanel;
    anchors.left: parent.left;
    anchors.verticalCenter: parent.verticalCenter;
    width: 60;
    height: parent.height * 0.7;

    Component.onCompleted: {
      var options = [
        { text: "Home", image_source: "qrc:/QML/stockMarket/frontend/icons/home_icon.png"},
        { text: "Filter", image_source: "qrc:/QML/stockMarket/frontend/icons/filter_icon.png" },
        { text: "Stats", image_source: "qrc:/QML/stockMarket/frontend/icons/stats_icon.png" }
      ];
      menuPanel.updateOptions(options);
    }
  }
}
