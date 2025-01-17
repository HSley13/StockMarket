import QtQuick 2.15

Rectangle {
  id: menuBar;
  color: "transparent";

  ListView {
    anchors.fill: parent;
    model: ListModel {
      id: listModel;
    }

    delegate: Rectangle {
      height: 60;
      width: parent.width;
      color: "transparent";

      Column {
        anchors.top: parent.top;
        anchors.horizontalCenter: parent.horizontalCenter;

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
          anchors.horizontalCenter: parent.horizontalCenter;
        }
      }

      MouseArea {
        anchors.fill: parent;
        onClicked:{ 
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
  }

  function handleItemClick(text) {
    switch (text) {
      case "Home":
        console.log("Home clicked")
      break
      case "Filter":
        console.log("Filter clicked")
      break
      case "Stats":
        console.log("Stats clicked")
      break
      default:
        console.log("Other option clicked:", text)
    }
  }
}
