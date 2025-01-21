import QtQuick
import QtCharts

Rectangle{
  width: 400;
  height: 400;
  radius: 40;
  PolarChartView{
    title: "Static Demo: Two Series, common Axes"
    anchors.fill: parent;
    legend.visible: true;
    antialiasing: true;

    ValueAxis{
      id: axisAngular;
      min: 0;
      max: 20;
      tickCount: 9;
    }

    ValueAxis{
      id: axisRadial;
      min: -0.5;
      max: 1.5;
    }

    SplineSeries{
      id: series1;
      axisAngular: axisAngular;
      axisRadial: axisRadial;
      pointsVisible: true;
    }

    ScatterSeries{
      id: series2;
      axisAngular: axisAngular;
      axisRadial: axisRadial;
      markerSize: 10;
    }

    Component.onCompleted: {
      for(var i = 0; i <= 20; i++) {
        series1.append(i, Math.random());
        series2.append(i, Math.random());
      }
    }
  }
}
