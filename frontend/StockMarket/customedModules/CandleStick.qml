import QtQuick 2.15
import QtCharts 2.15

Rectangle{
  width: 400;
  height: 400;
  radius: 40;
  property alias series: series;

  ChartView{
    id: chartView;
    anchors.fill: parent;
    title: "Candlestick Chart";
    legend.visible: false;
    antialiasing: true;

    CandlestickSeries{
      id: series;
      increasingColor: "green";
      decreasingColor: "red";

      function updateData(){
        series.clear();
        console.log("updateData called");
        for (var i = 0; i < stockProvider.stockData.length / 10; i++) {
          console.log(stockProvider.stockData[i].timestamp);
          var candlestick = Qt.createQmlObject(
            "import QtQuick 2.15; import QtCharts 2.15; CandlestickSet { " +
            "timestamp: " + stockProvider.stockData[i].timestamp + "; " +
            "open: " + stockProvider.stockData[i].open + "; " +
            "high: " + stockProvider.stockData[i].high + "; " +
            "low: " + stockProvider.stockData[i].low + "; " +
            "close: " + stockProvider.stockData[i].close + "; " +
            "}", series
            );
          series.append(candlestick);
          console.log(stockProvider.stockData[i].open);
        }
      }
    }
  }
}
