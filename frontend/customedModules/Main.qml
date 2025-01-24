import QtQuick;
import QtQuick.Controls;
import StockMarket;

ScrollView {
  anchors.fill: parent;

  CandleStickModel{
    id: candleStickModel;
  }

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
