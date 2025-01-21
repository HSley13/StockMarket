import QtQuick
import QtQuick.Controls

Rectangle 
{
    Rectangle 
    {
        id: topBarBat;

        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;
        
        height: 50;
        color: "black";

        Text 
        {
            id: titleTextBat;

            anchors.centerIn: parent;

            text: "I am Batman!";

            color: "white";
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere;

            font.pixelSize: 20;
            font.bold: true;
        }
    }

    Rectangle
    {
        id: mainSectionBat;

        anchors.top: topBarBat.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.topMargin: 20;

        RoundedImage
        {
          id: batmanImg;

          anchors.horizontalCenter: parent.horizontalCenter;

          width: parent.width / 2;
          height: width;
          imageSource:"qrc:/QML/stockMarket/icons/Batman.png";
        }

        Button
        {
            id: batmanButton;

            anchors.top: batmanImg.bottom;
            anchors.left: parent.left;
            anchors.right: parent.right;
            anchors.topMargin: 20;

            text: "-> Batman <-";
            font.pixelSize: 20;
            font.bold: true;

            onClicked: mainStack.push(ironman);
        }
    }
}

