import QtQuick;
import QtQuick.Controls.Basic;

Button{
  id: root;

  contentItem: Text {
    text: root.text
    opacity: enabled ? 1.0 : 0.3;
    color: "white";
    horizontalAlignment: Text.AlignHCenter;
    verticalAlignment: Text.AlignVCenter;
    elide: Text.ElideRight;
  }

  background: Rectangle {
    width: root.width;
    height: root.height;    
    opacity: enabled ? 1 : 0.3;
    border.color: root.down ? "black" : "gray";
    border.width: 2;
    radius: 15;

    gradient: Gradient {
      GradientStop { position: 0.0; color: "#f7b231" }
      GradientStop { position: 1.0; color: "#e05307" }
    }
  }
}
