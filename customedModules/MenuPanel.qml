import QtQuick 2.15

Rectangle {
  id: menuBar;
  color: "transparent";
  property int activeIndex;

  ListView {
    anchors.fill: parent;
    model: ListModel {
      id: listModel;
    }

    delegate: Rectangle {
      height: 60;
      width: parent.width;

      color: menuBar.activeIndex === index ? "black" : "transparent";

      Column {
        anchors.centerIn: parent;

        RoundedImage {
          width: 30;
          height: width;
          imageSource: model.image_source;
          anchors.horizontalCenter: parent.horizontalCenter;
        }

        Text {
          text: model.text;
          color: "white";
          font.pixelSize: 12;
          font.bold: true;
          anchors.horizontalCenter: parent.horizontalCenter;
        }
      }

      MouseArea {
        anchors.fill: parent;
        onClicked: { 
          menuBar.activeIndex = index;
          handleItemClick(model.text);
        }
      }
    }
  }

  function updateOptions(options){
    listModel.clear();

    for(var i = 0; i < options.length; i++){
      var text = options[i].text || "";
      var image_source = options[i].image_source || "";

      listModel.append({"text": text, "image_source": image_source});
    }
    activeIndex = 0;
  }

  function handleItemClick(text) {
    switch (text) {
      case "Home":
        console.log("Home clicked")
      break;
      case "Filter":
        console.log("Filter clicked")
      break;
      case "Stats":
        console.log("Stats clicked")
      break;
      default:
        console.log("Other option clicked:", text)
    }
  }
}
