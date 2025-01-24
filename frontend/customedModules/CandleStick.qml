import QtQuick 2.15
import QtCharts 2.15

Rectangle{
  width: 400;
  height: 400;
  radius: 40;

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

      VCandlestickModelMapper{
        id: modelMapper;
        model: candleStickModel;
        timestampRow: 1;
        openRow: 2;
        highRow: 3;
        lowRow: 4;
        closeRow: 5;
        onModelChanged: {
            console.log("Candlestick series data model updated");
        }
      }
    }
  }
}
