import QtQuick 2.15;

Rectangle{
  color: "white";

  ListView{
    anchors.fill: parent;

    model: ListModel{
      id: listModel;
    }

    delegate: Rectangle{
      anchors.fill: parent;
      color: "white";
      
      Column{
        RoundedImage{
          width: 35;
          height: width;

          imageSource: model.image_source;
        }

        Text{
          text: model.text;
          color: "white";
        }
      }

      MouseArea{
        anchors.fill: parent;
        onClicked: handleItemClick(index, model.text, model.image_source);
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

  function handleItemClick(index, text, image_source){
    switch (text) {
      case "Home":
        console.log("Home clicked");
      break;
      case "Filter":
        console.log("Filter clicked");
      break;
      case "Stats":
        console.log("Stats clicked");
      break;
      default:
        console.log("Other option clicked:", text);
    }
  }

  Component.onCompleted: {
    listModel.append({ "text": "Home", "image_source": "qrc:/QML/stockMarket/icons/home_icon.png" })
    listModel.append({ "text": "Filter", "image_source": "qrc:/QML/stockMarket/icons/filter_icon.png" })
    listModel.append({ "text": "Stats", "image_source": "qrc:/QML/stockMarket/icons/stats_icon.png" })
  }
}

