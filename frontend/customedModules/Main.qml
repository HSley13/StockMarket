import QtQuick 2.0
import QtQuick.Controls 2.5
import stockMarket

ScrollView {
    anchors.fill: parent;

    Component{
      id: homeWindow;
      HomeWindow{}
    }

    StackView{
        id: mainStack;
        anchors.fill: parent;
        initialItem: homeWindow;
    }
}
