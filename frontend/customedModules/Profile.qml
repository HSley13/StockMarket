import QtQuick 2.15
import QtCharts 2.15

Rectangle {
    id: root
    property int __activeIndex: 0
    property real __intervalCoefficient: 0
    width: 400
    height: 400
    radius: 40

    ChartView {
        id: chartView
        anchors.fill: parent
        title: "Wheel of Fortune"
        legend.visible: false
        antialiasing: true

        PieSeries {
            id: wheelOfFortune
            horizontalPosition: 0.3
        }

        SplineSeries {
            id: splineSeries
        }

        ScatterSeries {
            id: scatterSeries
        }
    }

    Component.onCompleted: {
        // Generate application data
        __intervalCoefficient = Math.random() + 0.25;

        for (var i = 0; i < 20; i++) {
            wheelOfFortune.append("", 1);
        }

        var interval = 1;
        for (var j = 0; interval < 800; j++) {
            interval = __intervalCoefficient * j * j;
            splineSeries.append(j, interval);
        }
        chartView.axisX(scatterSeries).max = j;
        chartView.axisY(scatterSeries).max = 1000;
    }

    Timer {
        id: highlightTimer
        interval: 500
        running: true
        repeat: true
        onTriggered: {
            // Highlight a single pie slice
            if (wheelOfFortune.count > 0) {
                wheelOfFortune.at(root.__activeIndex).exploded = false;
                root.__activeIndex = (root.__activeIndex + 1) % wheelOfFortune.count;
                wheelOfFortune.at(root.__activeIndex).exploded = true;

                // Animate scatter series
                scatterSeries.clear();
                scatterSeries.append(root.__activeIndex, __intervalCoefficient * root.__activeIndex * root.__activeIndex);
                scatterSeries.color = Qt.tint(scatterSeries.color, "#05FF0000");
                scatterSeries.markerSize += 0.5;
            }
        }
    }

    Timer {
        id: blinkTimer
        interval: 300
        running: false
        repeat: true
        onTriggered: {
            // Make the active slice blink
            if (wheelOfFortune.count > 0) {
                var slice = wheelOfFortune.at(root.__activeIndex);
                slice.borderWidth = 2;
                var switchColor = slice.borderColor;
                slice.borderColor = slice.color;
                slice.color = switchColor;
            }
        }
    }

    Connections {
        target: highlightTimer
        function onRunningChanged() {
            if (!highlightTimer.running) {
                blinkTimer.start();
            }
        }
    }

    function stopWheel() {
        highlightTimer.stop();
    }
}
