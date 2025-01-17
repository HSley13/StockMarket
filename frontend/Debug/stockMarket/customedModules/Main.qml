import QtQuick 2.0
import QtQuick.Controls 2.5
import stockMarket

ScrollView {
    anchors.fill: parent;

    StackView{
        id: mainStack;
        anchors.fill: parent;
        initialItem: homeWindow;
    }

    Component{
      id: homeWindow;
      HomeWindow{}
    }
}
